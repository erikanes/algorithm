#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll M = 1000000000;
ll dp[101][10];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i < 10; ++i)
        dp[1][i] = 1;
    
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (0 == j) dp[i][j] += dp[i-1][j+1] % M;
            else if (9 == j) dp[i][j] += dp[i-1][j-1] % M;
            else dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1]) % M;
        }
    }
    
    cout << accumulate(dp[N], dp[N] + 10, 0ll) % M;
    
    return 0;
}