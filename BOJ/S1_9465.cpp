#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int T, n;
int sticker[2][100001];
int dp[2][100001];

int main()
{
	FASTIO;

	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n * 2; ++i)
			cin >> sticker[i / n][i % n];

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[0][0] + sticker[1][1];

		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + sticker[1][i];
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}