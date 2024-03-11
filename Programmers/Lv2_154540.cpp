#include <bits/stdc++.h>
using namespace std;

const int bx[4] = { 0, -1, 0, 1 };
const int by[4] = { -1, 0, 1, 0 };

vector<int> solution(vector<string> maps)
{
	vector<int> answer;
	int row = maps.size();
	int column = maps[0].size();

	auto bfs = [&](int x, int y)
	{
		int result = maps[x][y] - '0';
		queue<pair<int, int>> q;
		q.emplace(x, y);
		maps[x][y] = 'X';

		while (!q.empty())
		{
			auto [cx, cy] = q.front(); q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int dx = cx + bx[i];
				int dy = cy + by[i];

				if (dx < 0 || dx >= row || dy < 0 || dy >= column || 'X' == maps[dx][dy]) continue;

				q.emplace(dx, dy);
				result += maps[dx][dy] - '0';
				maps[dx][dy] = 'X';
			}
		}

		return result;
	};

	for (int i = 0; i < maps.size(); ++i)
	{
		for (int j = 0; j < maps[i].size(); ++j)
		{
			if ('X' == maps[i][j]) continue;
			answer.emplace_back(bfs(i, j));
		}
	}

	if (answer.empty()) answer.emplace_back(-1);

	sort(answer.begin(), answer.end());

	return answer;
}