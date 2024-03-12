#include <bits/stdc++.h>
using namespace std;

int N, M, answer = 0;
int tetromino[501][501];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void make_polyomino(int x, int y, int sum, int depth)
{
	if (4 == depth)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || !tetromino[nx][ny]) continue;

		int t = tetromino[nx][ny];
		tetromino[nx][ny] = 0;
		make_polyomino(nx, ny, sum+t, depth+1);
		tetromino[nx][ny] = t;
	}
}

void make_T(int x, int y)
{
	if (x+1 < N && y+2 < M)
		answer = max(answer, tetromino[x][y] + tetromino[x][y+1] + tetromino[x][y+2] + tetromino[x+1][y+1]);
	if (x+2 < N && y+1 < M)
		answer = max(answer, tetromino[x][y+1] + tetromino[x+1][y] + tetromino[x+1][y+1] + tetromino[x+2][y+1]);
	if (x+1 < N && y+2 < M)
		answer = max(answer, tetromino[x][y+1] + tetromino[x+1][y] + tetromino[x+1][y+1] + tetromino[x+1][y+2]);
	if (x+2 < N && y+1 < M)
		answer = max(answer, tetromino[x][y] + tetromino[x+1][y] + tetromino[x+1][y+1] + tetromino[x+2][y]);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) cin >> tetromino[i][j];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			make_polyomino(i, j, 0, 0);
			make_T(i, j);
		}
	}

	cout << answer;

	return 0;
}