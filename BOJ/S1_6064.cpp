#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int year = x;
		int cnt = 0;
		while (y != (year - 1) % N + 1 && cnt <= N) year += M, ++cnt;

		if (cnt <= N) cout << year << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}