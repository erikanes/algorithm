#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool recursion(const string& s, int l, int r) {
    cnt++;
    if (l >= r)
        return true;
    else if (s[l] != s[r])
        return false;
    else
        return recursion(s, l+1, r-1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        string s;
        cin >> s;
        if (recursion(s, 0, s.size()-1))
            cout << 1;
        else
            cout << 0;
        cout << ' ' << cnt << '\n';
    }
    return 0;
}