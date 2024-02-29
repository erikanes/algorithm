#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		int t = 0x3f3f3f3f;

		for (int j = 1; j * j <= i; ++j)
			t = min(t, dp[i - j * j]);

		dp[i] = t + 1;
	}

	cout << dp[n];

	return 0;
}