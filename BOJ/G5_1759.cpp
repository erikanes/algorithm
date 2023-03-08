#include <bits/stdc++.h>
using namespace std;

bool check(int l, char str[]) {
    int vow = 0, con = 0;
    for (int i = 0; i < l; ++i) {
        if (str[i] == 'a' ||
            str[i] == 'e' ||
            str[i] == 'i' ||
            str[i] == 'o' ||
            str[i] == 'u')
            ++vow;
        else
            ++con;
    }
    return (vow >= 1) && (con >= 2);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, c;
    char pw[16];
    bool visited[16] = {};
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        cin >> pw[i];
        visited[clamp(i, 0, l - 1)] = true;
    }

    sort(pw, pw + c);

    do {
        char str[16];
        int idx = 0;
        for (int i = 0; i < c; ++i)
            if (visited[i]) str[idx++] = pw[i];
        str[idx] = '\0';

        if (check(l, str))
            cout << str << '\n';
    } while (prev_permutation(visited, visited + c));

    return 0;
}