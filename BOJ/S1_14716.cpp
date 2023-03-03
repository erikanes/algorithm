#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int graph[251][251];
bool visited[251][251];
int m, n, ans;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m
                || visited[ny][nx] || !graph[ny][nx])
                continue;

            q.push({ nx,ny });
            visited[ny][nx] = true;
        }
    }
    ++ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (graph[i][j] && !visited[i][j]) bfs(j, i);

    cout << ans;

    return 0;
}