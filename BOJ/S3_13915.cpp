#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    auto make_bit = [](auto i) {
        int n = i, bit = 0;
        while (n > 0) {
            bit |= 1 << ((n%10)-1);
            n /= 10;
        }
        return bit;
    };

    int t;
    while (cin >> t) {
        set<int> s;
        while (t--) {
            int n;
            cin >> n;
            s.insert(make_bit(n));
        }
        cout << s.size() << '\n';
    }

    return 0;
}