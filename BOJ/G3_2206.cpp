#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int N, M;
string maps[1001];
int visited[1001][1001][2];

bool is_out_of_bound(int x, int y)
{
	return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs()
{
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	visited[0][0][0] = 1;

	while (!q.empty())
	{
		auto [x, y, broken] = q.front();
		q.pop();

		if (x == N - 1 && y == M - 1)
			return visited[x][y][broken];

		for (int i = 0; i < 4; ++i)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];

			if (is_out_of_bound(nx, ny)) continue;
			else if (visited[nx][ny][broken]) continue;

			if ('1' == maps[nx][ny] && !broken)
			{
				visited[nx][ny][1] = visited[x][y][broken] + 1;
				q.emplace(nx, ny, 1);
			}
			else if ('0' == maps[nx][ny])
			{
				visited[nx][ny][broken] = visited[x][y][broken] + 1;
				q.emplace(nx, ny, broken);
			}
		}
	}

	return -1;
}

int main()
{
	FASTIO;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> maps[i];

	cout << bfs();

	return 0;
}