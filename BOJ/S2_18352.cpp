#include <bits/stdc++.h>
using namespace std;
vector<int> adj[300001];
bool visited[300001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k, x;
    cin >> n >> m >> k >> x;

    while (m--) {
        int st, en;
        cin >> st >> en;
        adj[st].push_back(en);
    }

    queue<pair<int, int>> q;
    vector<int> ans;
    q.push({ 0, x });
    visited[x] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int dist = cur.first + 1;
        if (dist > k) continue;

        for (auto& i : adj[cur.second]) {
            if (!visited[i]) {
                q.push({ dist, i });
                if (dist == k) ans.push_back(i);
                visited[i] = true;
            }
        }
    }

    if (ans.empty())
        cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (auto& i : ans)
            cout << i << '\n';
    }

    return 0;
}