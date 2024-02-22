#include <bits/stdc++.h>
using namespace std;

void recursive(int _x, int _y, int _n)
{
    if (1 == (_x / _n) % 3 && 1 == (_y / _n) % 3)
        cout << ' ';

    else
    {
        if (0 == _n / 3) cout << '*';
        else recursive(_x, _y, _n / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y) recursive(x, y, n);
        cout << '\n';
    }

    return 0;
}