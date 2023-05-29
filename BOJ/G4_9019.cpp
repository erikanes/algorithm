#include <bits/stdc++.h>
using namespace std;
int A, B;

string bfs()
{
	queue<pair<int, string>> q;
	bool visited[10001] = {};
	q.push({ A, "" });
	visited[A] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == B)
			return cur.second;

		int D = cur.first * 2 % 10000;
		if (!visited[D])
		{
			visited[D] = true;
			q.push({ D, cur.second + "D"});
		}

		int S = cur.first - 1 < 0 ? 9999 : cur.first - 1;
		if (!visited[S])
		{
			visited[S] = true;
			q.push({ S, cur.second + "S"});
		}

		int L = (cur.first % 1000) * 10 + (cur.first / 1000);
		if (!visited[L])
		{
			visited[L] = true;
			q.push({ L, cur.second + "L"});
		}

		int R = (cur.first / 10) + (cur.first % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = true;
			q.push({ R, cur.second + "R"});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		cin >> A >> B;
		cout << bfs() << '\n';
	}

	return 0;
}