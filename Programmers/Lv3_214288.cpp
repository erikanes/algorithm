#include <bits/stdc++.h>

using namespace std;

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0x3f3f3f3f;
    vector<vector<int>> orders;
    vector<int> v(k + 1, 1);

    auto make_allcase = [&](auto& _self, int _idx, int _person)
    {
        if (_person <= 0)
        {
            orders.push_back(v);
            return;
        }

        for (int i = _idx; i < k + 1; ++i)
        {
            ++v[i];
            _self(_self, i, _person - 1);
            --v[i];
        }

        return;
    };

    auto calc = [&](const auto& _order) -> int
    {
        int result = 0;

        priority_queue<int, vector<int>, greater_equal<int>> pq[6];

        for (int i = 1; i < k + 1; ++i)
            for (int j = 0; j < _order[i]; ++j) pq[i].push(0);

        for (auto& r : reqs)
        {
            int start = r[0];
            int progress = r[1];
            int type = r[2];

            auto cur = pq[type].top(); pq[type].pop();

            if (cur > start)
            {
                result += cur - start;
                pq[type].push(cur + progress);
            }

            else if (cur < start)
                pq[type].push(start + progress);

            else
                pq[type].push(cur + progress);
        }

        return result;
    };

    make_allcase(make_allcase, 1, n - k);

    for (const auto& order : orders)
        answer = min(answer, calc(order));

    return answer;
}