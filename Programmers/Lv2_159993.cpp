#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int bfs(vector<string> maps, char st, char goal) {    
    const int w = maps[0].length();
    const int h = maps.size();
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    auto start_point = [&](auto c) {
        for (int x = 0; x < w; ++x)
            for (int y = 0; y < h; ++y)
                if (maps[y][x] == st) return make_pair(x, y);
    };

    int dist[101][101] = {};
    queue<pair<int,int>> q;

    q.push(start_point(st));

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h || maps[ny][nx] == 'X')
                continue;

            dist[ny][nx] = dist[cur.Y][cur.X] + 1;

            if (maps[ny][nx] == goal)
                return dist[ny][nx];

            maps[ny][nx] = 'X';
            q.push({nx, ny});
        }
    }
    return -999999;
}

int solution(vector<string> maps) {
    int ans = 0;

    ans += bfs(maps, 'S', 'L');
    ans += bfs(maps, 'L', 'E');

    if (ans < 0)
        return -1;
    else
        return ans;
}