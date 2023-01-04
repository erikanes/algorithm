#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    for (const auto& i : tangerine) m[i]++;

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const auto& p1, const auto& p2) { return p1.second > p2.second; });

    for (int i = 0; i < v.size(); ++i) {
        if (k - v[i].second <= 0) return i+1;
        k -= v[i].second;
    }
}