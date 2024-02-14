#include <bits/stdc++.h>
using namespace std;

bool isused[10];
set<string> s;
int n, k;
int card[10];

void func(const string& _str, int _cnt)
{
    if (k == _cnt)
    {
        s.insert(_str);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (isused[i])
            continue;

        isused[i] = true;
        func(_str + to_string(card[i]), _cnt + 1);
        isused[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> card[i];

    func("", 0);

    cout << s.size();

    return 0;
}