#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board)
{
	auto is_complete = [&](char c) -> bool
	{
		for (int i = 0; i < 3; ++i)
		{
			if (board[i][0] + board[i][1] + board[i][2] == c * 3) return true;
			else if (board[0][i] + board[1][i] + board[2][i] == c * 3) return true;
		}

		if (board[0][0] + board[1][1] + board[2][2] == c * 3) return true;
		else if (board[0][2] + board[1][1] + board[2][0] == c * 3) return true;

		return false;
	};

	auto count_mark = [&](char c)
	{
		int result = 0;
		for (int i = 0; i < 3; ++i) result += count(board[i].begin(), board[i].end(), c);
		return result;
	};

	int o = count_mark('O');
	int x = count_mark('X');
	bool o_com = is_complete('O');
	bool x_com = is_complete('X');

	if (o_com && x_com) return 0;
	else if (o_com && o - x != 1) return 0;
	else if (x_com && x - o != 0) return 0;
	else if (o - x >= 2 || x - o >= 1) return 0;

	return 1;
}