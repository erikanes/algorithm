#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, M;
	cin >> N >> M;

	vector<ll> v(N + 1);
	for (ll i = 0; i < N; ++i) cin >> v[i];

	sort(v.begin(), v.end());

	ll left = 0, right = *v.rbegin(), ans = 0;
	while (left < right)
	{
		ll total = 0, mid = (left + right + 1) / 2;

		for (auto& i : v) total += i - mid > 0 ? i - mid : 0;

		if (total >= M)	left = mid, ans = mid;
		else right = mid - 1;
	}

	cout << ans;

	return 0;
}