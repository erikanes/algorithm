#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, cnt = 0, ans = 666;
	cin >> N;

	while (true)
	{
		if (string::npos != to_string(ans).find("666")) ++cnt;
		if (cnt == N) break;
		++ans;
	}

	cout << ans;

	return 0;
}