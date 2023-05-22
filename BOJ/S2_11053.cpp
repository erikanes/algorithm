#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N+1);
	vector<int> dp(N+1, 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		for (int j = 0; j < i; ++j)
			if (A[i] > A[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;

	return 0;
}