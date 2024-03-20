#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int V, far, answer;
vector<pair<int, int>> adj[100001];
bitset<100001> visited;

/*
풀이 핵심
- 2번의 dfs를 통해 산출
- 첫번째 dfs에서 임의의 노드(1번)에서부터 가장 바깥쪽의 노드 탐색
- 두번째 dfs에서 첫번째 dfs로 구한 노드에서부터 가장 멀리있는 노드 탐색
*/

void dfs(int node, int costs)
{
	visited.set(node, true);

	for (auto& [v, cost] : adj[node])
	{
		if (visited[v]) continue;
		dfs(v, costs + cost);
	}

	if (costs > answer)
	{
		answer = costs;
		far = node;
	}
}

int main()
{
	FASTIO;

	cin >> V;
	
	for (int i = 0; i < V; ++i)
	{
		int v;
		cin >> v;
		while (true)
		{
			int next, cost;
			cin >> next;
			if (-1 == next) break;
			cin >> cost;

			adj[v].emplace_back(next, cost);
		}
	}

	dfs(1, 0);
	answer = 0;
	visited.reset();
	dfs(far, 0);

	cout << answer;

	return 0;
}