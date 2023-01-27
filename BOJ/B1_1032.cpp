#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<string> v;
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < v[0].length(); ++i) {
        bool b = true;
        for (int j = 1; j < v.size(); ++j) {
            b = b && (v[0][i] == v[j][i]);
        }
        if (b)
            cout << v[0][i];
        else
            cout << '?';
    }

    return 0;
}