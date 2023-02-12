#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin >> m;

    ui bit = 0;
    auto make_bit = [](auto i)->ui { return 1 << (i - 1); };
    auto check_bit = [&bit, make_bit](auto i)->ui { return bit & make_bit(i) ? 1 : 0; };

    while (m--) {
        string s;
        int x;
        cin >> s;
        if (s == "add") { cin >> x; bit |= make_bit(x); }
        else if (s == "remove") { cin >> x; bit &= ~make_bit(x); }
        else if (s == "check") { cin >> x; cout << check_bit(x) << '\n'; }
        else if (s == "toggle") { cin >> x; bit ^= make_bit(x); }
        else if (s == "all") bit |= -1;
        else if (s == "empty") bit ^= bit;
    }

    return 0;
}