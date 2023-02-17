#include <bits/stdc++.h>
using namespace std;

int bit[101];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> bit[i];
    cin >> t;
    
    while (t--) {
        int w, s;
        cin >> w >> s;
        
        if (w == 1)
            for (int i = s; i <= n; i += s) bit[i] = !bit[i];
        else {
            int range = 1;
            while ((s-range > 0) && (s+range <= n)) {
                if (bit[s-range] != bit[s+range]) break;
                bit[s-range] = !bit[s-range];
                bit[s+range] = !bit[s+range];
                ++range;
            }
            bit[s] = !bit[s];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << bit[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    
    return 0;
}