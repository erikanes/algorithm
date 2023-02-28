#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, mx;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
char maps[51][51];

void bfs(pair<int, int> st) {
    int dist[51][51] = {};
    queue<pair<int, int>> q;
    q.push(st);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (maps[ny][nx] == 'W' || dist[ny][nx] != 0) continue;
            if (nx == st.X && ny == st.Y) continue;

            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            mx = max(mx, dist[ny][nx]);
            q.push({ nx,ny });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> maps[i][j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (maps[i][j] == 'L') bfs({ j,i });
    }

    cout << mx;

    return 0;
}