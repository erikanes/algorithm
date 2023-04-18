#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v(8);
    vector<int> v1 = { 1,2,3,4,5,6,7,8 };
    vector<int> v2 = { 8,7,6,5,4,3,2,1 };
    auto cmp = [](const auto& v1, const auto& v2)
    {
        for (auto i = 0; i < v1.size(); ++i)
            if (v1[i] != v2[i]) return false;
        return true;
    };

    for (int i = 0; i < 8; ++i)
        cin >> v[i];

    if (cmp(v, v1))
        cout << "ascending";
    else if (cmp(v, v2))
        cout << "descending";
    else
        cout << "mixed";

    return 0;
}