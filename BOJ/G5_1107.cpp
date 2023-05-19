#include <bits/stdc++.h>
using namespace std;

bool isBroken[10];

int useRemote(int n)
{
	int cnt = 0;

	do
	{
		if (isBroken[n % 10]) return 0;
		n /= 10;
		++cnt;
	} while (n);

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	while (M--)
	{
		int n;
		cin >> n;
		isBroken[n] = true;
	}

	int ans = abs(N - 100);
	for (int i = 0; i <= 1000000; ++i)
	{
		int m = useRemote(i);
		int t = m > 0 ? abs(N - i) + m : ans;
		ans = ans > t ? t : ans;
	}

	cout << ans;

	return 0;
}