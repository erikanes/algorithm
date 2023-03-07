#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    v.reserve(1000001);
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    int st = v.begin()->X, en = v.begin()->Y;
    int ans = 0;

    for_each(v.begin() + 1, v.end(), [&](auto p) {
        if (p.X <= en && p.Y > en) en = p.Y;
        else if (p.X > en) { ans += en - st; st = p.X, en = p.Y; }}
    );

    ans += en - st;
    cout << ans;

    return 0;
}