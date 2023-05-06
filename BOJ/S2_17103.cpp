#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool isPrime[N + 1];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(isPrime+2, isPrime+N+1, true);

	for (int i = 2; i*i <= N; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= N; j += i)
				isPrime[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n, cnt = 0;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			if (isPrime[n - i] && isPrime[i])
			{
				++cnt;
				if (n - i == i)
					++cnt;
			}

		}

		cout << cnt / 2 << '\n';
	}

	return 0;
}