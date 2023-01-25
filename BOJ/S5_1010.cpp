#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int dp[31] = { 0, m };

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] * (m - i + 1) / i; // nCr = n-1Cr-1 + n-1Cr

        cout << dp[n] << '\n';
    }

    return 0;
}