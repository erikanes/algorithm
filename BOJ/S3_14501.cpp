// DP
#include <bits/stdc++.h>
using namespace std;

int dp[30];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int t, p;
        cin >> t >> p;
        // 내일까지 번돈이 오늘보다 적으면 오늘 번돈을 내일에 넣음 (일을 안한다)
        if (dp[i+1] < dp[i]) dp[i+1] = dp[i];
        // i+t일까지 번돈이 이번일을 받아서 버는 돈보다 적으면 이번일을 받아서 버는 돈을 i+t일에 넣음 (일을 한다) 
        if (dp[i+t] < dp[i]+p) dp[i+t] = dp[i] + p;
    }
    
    cout << dp[n];  
    return 0;
}