#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;

    int ans = 0, cnt = 0;
    for (int i = 2; i < s.size(); ++i) {
        if (s[i - 2] == 'I' && s[i - 1] == 'O' && s[i] == 'I')
            ++cnt, ++i;
        else
            cnt = 0;

        if (cnt == n) {
            ++ans;
            --cnt;
        }
    }

    cout << ans;

    return 0;
}