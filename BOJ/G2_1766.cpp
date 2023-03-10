#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ind(n + 1);
    vector<vector<int>> adj(n + 1);

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        ++ind[y];
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i)
        if (!ind[i]) q.push(i);

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        cout << cur << ' ';

        for (auto& i : adj[cur]) {
            --ind[i];
            if (!ind[i]) q.push(i);
        }
    }

    return 0;
}