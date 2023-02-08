#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    auto func = []() { int n; cin >> n; return n; };
    int t;
    cin >> t;

    while (t--) {
        unordered_set<int> s;
        int n, m;

        cin >> n;
        while (n--)
            s.insert(func());

        cin >> m;
        vector<int> v;
        v.reserve(m);

        while (m--)
            v.emplace_back(func());

        for (const auto& i : v)
            cout << s.count(i) << '\n';
    }

    return 0;
}