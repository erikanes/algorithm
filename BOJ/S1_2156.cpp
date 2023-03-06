#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int glass[10001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> glass[i];

    dp[1] = glass[1]; dp[2] = glass[1] + glass[2];
    for (int i = 3; i <= n; ++i)
        dp[i] = max(max(dp[i-2] + glass[i], dp[i-3] + glass[i-1] + glass[i]), dp[i-1]);

    cout << dp[n];
    return 0;
}