#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int maps[1001][1001];
bool visited[1001][1001];
int answer[1001][1001];

const int dirX[4] = { -1, 0, 1, 0 };
const int dirY[4] = { 0, -1, 0, 1 };

#define X cur.second
#define Y cur.first

int main()
{
    int n, m;
    cin >> n >> m;
    queue<P> q;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            cin >> maps[y][x];

            if (1 == maps[y][x])
                answer[y][x] = -1;

            else if (2 == maps[y][x])
            {
                q.push({ y, x });
                visited[y][x] = true;
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dx = X + dirX[i];
            int dy = Y + dirY[i];

            if (0 > dx || m < dx || 0 > dy || n < dy || visited[dy][dx])
                continue;

            visited[dy][dx] = true;

            if (0 == maps[dy][dx])
                continue;

            answer[dy][dx] = answer[Y][X] + 1;
            q.push({ dy, dx });
        }
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
            cout << answer[y][x] << ' ';

        cout << '\n';
    }

    return 0;
}