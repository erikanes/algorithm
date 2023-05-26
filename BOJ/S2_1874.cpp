#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, cur = 0;
	stack<int> s;
	string ans;
	cin >> n;

	s.push(0);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		while (cur <= n && !s.empty())
		{
			if (s.top() == num)
			{
				s.pop();
				ans.push_back('-');
				break;
			}
			else if (s.top() < num)
			{
				s.push(++cur);
				ans.push_back('+');
			}
			else
			{
				s.pop();
				ans.push_back('-');
			}
		}
	}

	if (s.empty() || cur != n)
		cout << "NO";
	else
		for (auto& c : ans)	cout << c << '\n';

	return 0;
}