#include <bits/stdc++.h>
using namespace std;

int T;
vector<int> adj[1001];

int topology_sort()
{
	vector<int> ind(1001, 0);
	vector<int> cost(1001, 0);
	vector<int> build(1001, 0);

	int N, K, W;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		adj[i].clear();
		cin >> cost[i];
	}

	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		adj[X].emplace_back(Y);
		++ind[Y];
	}

	cin >> W;

	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		if (!ind[i]) q.push(i);
		build[i] += cost[i];
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto& next : adj[node])
		{
			build[next] = max(build[next], build[node] + cost[next]);
			if (!--ind[next]) q.push(next);
		}
	}

	return build[W];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;

	while (T--) cout << topology_sort() << '\n';

	return 0;
}