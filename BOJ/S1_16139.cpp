#include <bits/stdc++.h>
using namespace std;
unordered_map<char, array<int, 200000>> m;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string S;
    int q;
    cin >> S >> q;

    m[S[0]][0] += 1;

    for (int i = 1; i < S.size(); ++i)
    {
        for (char j = 'a'; j <= 'z'; ++j)
            m[j][i] = m[j][i - 1];

        m[S[i]][i] += 1;
    }

    while (q--)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;

        if (0 == l)
            cout << m[a][r] << '\n';
        else
            cout << m[a][r] - m[a][l - 1] << '\n';
    }

    return 0;
}