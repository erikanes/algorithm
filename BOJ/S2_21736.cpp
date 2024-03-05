#include <bits/stdc++.h>
using namespace std;

#define X cur.first
#define Y cur.second

char campus[601][601];
int N, M, answer;
queue<pair<int, int>> q;

const int bx[4] = { 0, 1, 0, -1 };
const int by[4] = { -1, 0, 1, 0 };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> campus[i][j];
			if ('I' == campus[i][j])
			{
				q.push({ i, j });
				campus[i][j] = 'X';
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			auto dx = X + bx[i];
			auto dy = Y + by[i];

			if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
			else if ('X' == campus[dx][dy]) continue;

			q.push({ dx, dy });

			if ('P' == campus[dx][dy]) ++answer;
			campus[dx][dy] = 'X';
		}
	}

	if (answer > 0) cout << answer;
	else cout << "TT";

	return 0;
}