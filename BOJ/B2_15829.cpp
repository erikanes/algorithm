#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull M = 1234567891ull;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ull L, r = 1, ans = 0;
	cin >> L;
	for (ull i = 0; i < L; ++i)
	{
		char c;
		cin >> c;
		c = c - 'a' + 1;
		
		ans = (ans + ((ull)c * r)) % M;
		r = (r * 31) % M;
	}

	cout << ans;	

	return 0;
}