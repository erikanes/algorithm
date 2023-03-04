#include <bits/stdc++.h>
using namespace std;
#define next cur.first
#define cost cur.second

bool visited[101];
int game[101];

int bfs() {
    queue<pair<int, int>> q;
    visited[1] = true;
    for (int i = 2; i <= 7; ++i) {
        if (!visited[game[i]]) {
            visited[game[i]] = true;
            q.push({ game[i], 1 });
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i) {
            if (next + i > 100 || visited[game[next + i]]) continue;
            if (game[next + i] == 100) return cost + 1;
            visited[next + i] = true;
            q.push({ game[next + i], cost + 1 });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < 101; ++i) game[i] = i;
    for (int i = 0; i < n + m; ++i) {
        int s, e;
        cin >> s >> e;
        game[s] = e;
    }

    cout << bfs();

    return 0;
}