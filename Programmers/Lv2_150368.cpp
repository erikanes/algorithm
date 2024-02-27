#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    const int N = emoticons.size();
    vector<int> answer(2, 0);
    vector<int> discounts(N, 10);
    map<int, int, greater<int>> m;

    auto calc = [&]()
    {
        int subs = 0;
        int sums = 0;

        auto func = [&](const vector<int>& _user)
        {
            int s = 0;

            for (int i = 0; i < N; ++i)
            {
                if (discounts[i] >= _user[0])
                    s += emoticons[i] * ((100 - discounts[i]) / 100.f);
            }

            if (s >= _user[1]) ++subs;
            else sums += s;
        };

        for_each(users.begin(), users.end(), func);

        if (m[subs] < sums) m[subs] = sums;
    };

    auto dfs = [&](auto& _func, int _idx)
    {
        if (N <= _idx)
        {
            calc();
            return;
        }

        for (int i = 10; i <= 40; i += 10)
        {
            discounts[_idx] = i;
            _func(_func, _idx + 1);
        }
    };

    dfs(dfs, 0);

    const auto& p = *m.begin();
    answer[0] = p.first;
    answer[1] = p.second;    

    return answer;
}