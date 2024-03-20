#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 0x3f3f3f3f;
int TC;
int N, M, W, S, E, T;

vector<pair<int, int>> adj[501];
int dist[501];

bool bellman_ford(int node)
{
	dist[node] = 0;

	for (int i = 1; i <= N - 1; ++i)
	{
		for (int from = 1; from <= N; ++from)
		{
			for (auto& [to, cost] : adj[from])
			{				
				if (INF == dist[from])
					continue;

				dist[to] = min(dist[to], dist[from] + cost);
			}
		}
	}

	for (int from = 1; from <= N; ++from)
	{
		for (auto& [to, cost] : adj[from])
		{
			if (INF == dist[from])
				continue;
			else if (dist[to] > dist[from] + cost)
				return true;
		}
	}

	return false;
}

int main()
{
	FASTIO;

	cin >> TC;

	while (TC--)
	{
		cin >> N >> M >> W;

		fill_n(dist, N + 1, INF);
		for (int i = 0; i <= N; ++i)
			adj[i].clear();

		for (int i = 0; i < M; ++i)
		{
			cin >> S >> E >> T;

			adj[S].emplace_back(E, T);
			adj[E].emplace_back(S, T);
		}

		for (int i = 0; i < W; ++i)
		{
			cin >> S >> E >> T;

			auto it = find_if(adj[S].begin(), adj[S].end(), [](const auto& P) { return P.first == E; });
			
			if (adj[S].end() == it)
				adj[S].emplace_back(E, -T);
			else
				(*it).second = -T;
		}

		bool result = false;

		for (int i = 1; i <= N; ++i)
			if (INF == dist[i]) result |= bellman_ford(i);

		if (result)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}