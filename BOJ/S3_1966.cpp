#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, idx = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        while (n--) {
            int i;
            cin >> i;
            q.push({ i, idx });
            v.push_back({ i, idx++ });
        }

        sort(v.begin(), v.end(), [](auto p1, auto p2) { if (p1.first == p2.first) return p1.second < p2.second; return p1.first > p2.first; });

        for (int i = 0; i < v.size(); ++i) {
            while (v[i].first != q.front().first) {
                auto& temp = q.front();
                q.pop();
                q.push(temp);
            }
            if (q.front().second == m) {
                cout << i+1 << '\n';
                break;
            }
            q.pop();
        }
    }
    return 0;
}