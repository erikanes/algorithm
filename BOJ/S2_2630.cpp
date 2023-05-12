#include <bits/stdc++.h>
using namespace std;

int paper[128][128];
int answer[2]; // 흰0 파1

bool same_judge(int x, int y, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (paper[x][y] != paper[x + i][y + j])
				return false;
		}
	}

	return true;
}

void recursion(int x, int y, int n)
{
	if (same_judge(x, y, n))
	{
		answer[paper[x][y]]++;
		return;
	}

	int div = n / 2;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
			recursion(x + div * i, y + div * j, div);
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> paper[i][j];
	}

	recursion(0, 0, n);

	for (auto& ans : answer)
		cout << ans << '\n';

	return 0;
}