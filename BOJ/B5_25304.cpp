#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, n, ans = 0;
    cin >> x >> n;
    
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        ans += a * b;
    }
    
    if (x == ans) cout << "Yes";
    else cout << "No";
    
    return 0;
}