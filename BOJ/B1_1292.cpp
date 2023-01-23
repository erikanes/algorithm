#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    auto func = []() {
        int l, r;
        cin >> l >> r;
        int cnt = 1, n = 1, ans = 0;
        while (1) {
            for (int i = 0; i < n; ++i) {
                if (cnt++ >= l) ans += n;
                if (cnt > r) {
                    return ans;
                }
            }
            ++n;
        }
        return ans;
    };
    
    cout << func();
    
    return 0;
}