#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp1[500001];
ll dp2[500001];

long long solution(vector<int> sequence)
{
	auto n = sequence.size();
	int m = -1;
	dp1[0] = sequence[0];
	dp2[0] = -sequence[0];
	ll answer = max(dp1[0], dp2[0]);

	for (size_t i = 1; i < n; ++i)
	{
		ll s = sequence[i];
		dp1[i] = max(dp1[i - 1] + s * m, s * m);
		m *= -1;
		dp2[i] = max(dp2[i - 1] + s * m, s * m);
		answer = max(answer, max(dp1[i], dp2[i]));
	}

	return answer;
}