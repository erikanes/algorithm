#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int ans[100001];

void bfs(int r) {
    int idx = 1;
    queue<int> q;
    ans[r] = idx++;
    q.push(r);
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto& i : adj[cur])
        {
            if (ans[i])
                continue;
            
            ans[i] = idx++;
            q.push(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r;
    cin >> n >> m >> r;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end(), less<>());

    bfs(r);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';

    return 0;
}