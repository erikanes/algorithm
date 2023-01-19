#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= 100; ++i)
        dp[i] = dp[i-3] + dp[i-2];
    
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}