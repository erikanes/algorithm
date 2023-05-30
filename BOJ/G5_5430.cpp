#include <bits/stdc++.h>
using namespace std;
using DQ = deque<int>;

regex rx("\\[|\\]|,", regex::optimize);

void AC()
{
	string command, arr;
	int len;
	cin >> command >> len >> arr;

	DQ dq;
	int n;
	bool b = false;
	stringstream ss(regex_replace(arr, rx, " "));

	while (ss >> n) dq.push_back(n);

	arr.clear();

	for (auto& c : command)
	{
		if (c == 'R') b = !b;
		else if (c == 'D')
		{
			if (dq.empty())
			{
				cout << "error" << '\n';
				return;
			}

			if (b) dq.pop_back();
			else dq.pop_front();
		}
	}

	if (dq.empty())
	{
		cout << "[]" << '\n';
		return;
	}

	arr += "[";
	if (b) for (auto it = dq.rbegin(); it != dq.rend(); ++it) arr += to_string(*it) + ",";
	else for (auto it = dq.begin(); it != dq.end(); ++it) arr += to_string(*it) + ",";
	arr.back() = ']';

	cout << arr << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) AC();

	return 0;
}