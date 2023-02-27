#include <bits/stdc++.h>
using namespace std;
int dist[1001];
vector<pair<int,int>> adj[1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fill_n(dist, 1001, (int)1e9+1);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int st, en, co;
        cin >> st >> en >> co;
        adj[st].push_back({co, en});
    }
    int st, en;
    cin >> st >> en;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    q.push({0, st});
    dist[st] = 0;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        
        if (cur.first > dist[cur.second]) continue;
        
        for (auto p : adj[cur.second]) {
            int cost = p.first + dist[cur.second];
            int dest = p.second;
            if (cost < dist[dest]) {
                dist[dest] = cost;
                q.push({cost, dest});
            }
        }
    }
    cout << dist[en];   

    return 0;
}