#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long;

ul N, A[20], ans;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;

	while (N--)
	{
		bitset<20> b;
		ul t;
		cin >> t;
		b = t;
		for (auto i = 0; i < 20; ++i) A[i] += b[i];
	}

	cout << *max_element(A, A+20);

	return 0;
}