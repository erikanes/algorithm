#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
vector<int> arr[100001];
int ans[100001];

void dfs(const int& adj) {
    if (visited[adj]) return;
    
    static int idx = 1;
    ans[adj] = idx++;
    visited[adj] = true;

    for (const int& i : arr[adj])
        dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r;
    cin >> n >> m >> r;

    while (m--) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i)
        sort(arr[i].begin(), arr[i].end(), greater<>());

    dfs(r);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';

    return 0;
}