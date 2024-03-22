#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, far, answer;
vector<pair<int, int>> adj[10001];
bitset<10001> visited;

void dfs(int node, int costs)
{
	if (visited[node])
		return;

	visited.set(node, true);

	for (auto& [child, cost] : adj[node])
		dfs(child, costs + cost);

	if (answer < costs)
	{
		far = node;
		answer = costs;
	}
}

int main()
{
	FASTIO;

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int parent, child, cost;
		cin >> parent >> child >> cost;
		adj[parent].emplace_back(child, cost);
		adj[child].emplace_back(parent, cost);
	}

	dfs(1, 0);
	answer = 0;
	visited.reset();
	dfs(far, 0);

	cout << answer;

	return 0;
}