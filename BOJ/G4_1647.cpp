#include <bits/stdc++.h>
using namespace std;

vector<int> p(1000001, -1);
tuple<int, int, int> edge[1000001];

int find_root(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find_root(p[x]);
}

bool union_root(int u, int v)
{
    u = find_root(u); v = find_root(v);
    if (u == v) return false;
    if (p[u] == p[v]) --p[u];
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = { c, a, b };
    }

    sort(edge, edge + m);

    int cnt = 0, ans = 0, mx = 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        tie(c, a, b) = edge[i];
        if (!union_root(a, b)) continue;
        mx = c > mx ? c : mx;
        ans += c;
        if (++cnt == n - 1) break;
    }

    cout << ans - mx;

    return 0;
}