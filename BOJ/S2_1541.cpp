#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	vector<int> v;
	cin >> s;

	for (int i = 0; i < s.size();)
	{
		int j = i + 1, t = 0;
		while (j < s.size())
		{
			if (s[j] == '+')
			{
				t += stoi(s.substr(i, j - i));
				i = j + 1;
				j = i + 1;
				continue;
			}
			else if (s[j] == '-')
				break;
			++j;
		}
		t += stoi(s.substr(i, j - i));
		v.push_back(t);
		i = j + 1;
	}

	cout << v.front() - accumulate(v.begin() + 1, v.end(), 0);

	return 0;
}