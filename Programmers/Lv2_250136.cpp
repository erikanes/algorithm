#include <bits/stdc++.h>

using namespace std;

int visited[501][501];
const int X[4] = { -1, 0, 1, 0 };
const int Y[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> land) {
    int answer = 0;
    int lx = land[0].size();
    int ly = land.size();
    int id = 1;

    auto bfs = [&](int _sy, int _sx) -> int
    {
        queue<pair<int, int>> q;
        vector<int*> v;

        q.emplace(_sy, _sx);
        visited[_sy][_sx] = id;

        while (!q.empty())
        {
            auto& cur = q.front(); q.pop();
            v.emplace_back(&land[cur.first][cur.second]);

            for (int i = 0; i < 4; ++i)
            {
                int dx = cur.second + X[i];
                int dy = cur.first + Y[i];

                if (dx < 0 || dx >= lx || dy < 0 || dy >= ly || 0 == land[dy][dx] || visited[dy][dx]) continue;

                visited[dy][dx] = id;
                q.emplace(dy, dx);
            }
        }

        ++id;

        for (auto p : v)
            *p = v.size();

        return *v[0];
    };

    for (int x = 0; x < lx; ++x)
    {
        int result = 0;
        set<int> s;

        for (int y = 0; y < ly; ++y)
        {
            if (!land[y][x]) continue;
            else if (s.find(visited[y][x]) == s.end())
            {
                if (visited[y][x]) result += land[y][x];
                else result += bfs(y, x);

                s.insert(visited[y][x]);
            }

            while (y < ly && land[y++][x]); --y;
        }

        answer = max(answer, result);
    }

    return answer;
}