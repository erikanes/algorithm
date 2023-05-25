#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e12;

vector<ll> v;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll N, M, B;
	cin >> N >> M >> B;
	v.resize(N * M);
	for (int i = 0; i < N * M; ++i) cin >> v[i];

	sort(v.begin(), v.end(), greater<ll>());

	auto mm = minmax_element(v.begin(), v.end());
	pair<ll, ll> ans = { INF, INF };

	for (auto i = *mm.first; i <= *mm.second; ++i)
	{
		ll b = B, t = 0, h = 0;
		for (auto block : v)
		{
			ll diff = block - i;
			if (diff >= 0)
			{
				t += diff * 2;
				b += diff;
			}
			else
			{
				if (-diff > b)
				{
					t = INF;
					break;
				}
				t -= diff;
				b += diff;
			}
		}
		if (t <= ans.first) ans = { t, i };
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}