#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> v(1001, 0);

    for (const auto& w : weights)
        v[w] += 1;

    for (const auto& w : weights)
    {
        long long i = 0;

        if (0 == w % 2)
        {
            i = w / 2 * 3;
            if (1000 >= i) answer += v[i];
        }

        if (0 == w % 3)
        {
            i = w / 3 * 4;
            if (1000 >= i) answer += v[i];
        }

        i = w * 2;
        if (1000 >= i) answer += v[i];
    }

    for (auto i = 100; i <= 1000; ++i)
        if (2 <= v[i]) answer += v[i] * (v[i] - 1) / 2;

    return answer;
}