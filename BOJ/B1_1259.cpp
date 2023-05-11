#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (true)
	{
		string s;
		int n;
		bool b = true;
		cin >> n;
		if (!n) break;

		while (n)
		{
			s.push_back(n % 10 + '0');
			n /= 10;
		}

		for (auto i = 0; i < s.size() / 2; ++i)
			if (s[i] != s[s.size()-i-1]) b = false;

		if (b) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}