#include <bits/stdc++.h>
using namespace std;

const int mask = ~(-1 << 20);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1, 0);

    while (m--) {
        int m1, m2, m3;
        cin >> m1;

        switch (m1) {
        case 1:
            cin >> m2 >> m3;
            v[m2] = v[m2] | (1 << (m3-1));
            break;
        case 2:
            cin >> m2 >> m3;
            v[m2] = v[m2] & ~(1 << (m3-1));
            break;
        case 3:
            cin >> m2;
            v[m2] = (v[m2] << 1) & mask;
            break;
        case 4:
            cin >> m2;
            v[m2] = (v[m2] >> 1) & mask;
            break;
        }
    }

    set<int> s(v.begin()+1, v.end());
    cout << s.size();

    return 0;
}