#include <bits/stdc++.h>
using namespace std;
using BS = bitset<10>;

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    int N = dice.size();
    int halfN = N / 2;
    pair<int, BS> result = {0, BS()};

    BS b;
    BS mask("1111111111");
    mask = mask >> 10 - N;
    unordered_map<BS, vector<int>> m;

    auto recursive = [&](auto& self, int choice, int sum)
    {
        if (b.count() >= halfN)
        {
            m[b].push_back(sum);
            return;
        }

        for (int i = choice; i < N; ++i)
        {
            b.set(i, true);

            for (int j = 0; j < 6; ++j)
                self(self, i + 1, sum + dice[i][j]);

            b.set(i, false);
        }
    };

    auto wincount = [](auto& v1, auto& v2) -> int
    {
        int result = 0;

        for (auto& i : v1)
            result += lower_bound(v2.begin(), v2.end(), i) - v2.begin();

        return result;
    };

    recursive(recursive, 0, 0);

    for (auto& p : m)
        sort(p.second.begin(), p.second.end());

    for (auto& p : m)
    {
        BS A = p.first;
        BS B = mask & ~A;

        int r = wincount(m[A], m[B]);

        if (r > result.first)
            result.first = r, result.second = A;
    }

    for (int i = 0; i < 10; ++i)
        if (result.second.test(i)) answer.push_back(i + 1);

    return answer;
}