#include <bits/stdc++.h>
using namespace std;

int n, k;
int W[101], V[101];
int dp[101][100001];

int recursion(int i, int w)
{
    if (dp[i][w] > 0) return dp[i][w];
    if (i == n) return 0;

    int n1 = w + W[i] <= k ? V[i] + recursion(i + 1, w + W[i]) : 0;
    int n2 = recursion(i + 1, w);

    return dp[i][w] = max(n1, n2);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> W[i] >> V[i];
    cout << recursion(0, 0);

    return 0;
}