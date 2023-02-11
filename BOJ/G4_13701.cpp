#include <bits/stdc++.h>
using namespace std;

bitset<33554432> bit;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (!cin.eof()) {
		int n;
		cin >> n;
		if (bit[n]) continue;
		bit[n] = 1;
		cout << n << ' ';
	}

	return 0;
}