#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> p(101, vector<int>(101, 0));

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, answer = 0;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; ++i) fill_n(p[i].begin() + x, 10, 1);
	}
	for (auto& v : p) answer += accumulate(v.begin(), v.end(), 0);

	cout << answer;
	return 0;
}