#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;

    arr[0][0] = 0;
    arr[0][1] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i + 1; ++j) arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;

    cout << arr[n][k+1];

    return 0;
}