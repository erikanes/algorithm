#include <bits/stdc++.h>
using namespace std;
int op[300001];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, cut;
	cin >> n;
	cut = round(n * 0.15f);

	for (int i = 0; i < n; ++i)
		cin >> op[i];

	sort(op, op + n);

	if (0 == n) cout << 0;
	else cout << (int)round(accumulate(op + cut, op + n - cut, 0) / (n - cut * 2.f));

	return 0;
}