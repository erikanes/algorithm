#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> sums;
    vector<bool> removes(scores.size(), false);

    auto comp = [](const auto& v1, const auto& v2)
    {
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
    };

    auto isLower = [](const auto& v1, const auto& v2)
    {
        return v1[0] < v2[0] && v1[1] < v2[1];
    };

    auto isSumLower = [](const auto& v1, const auto& v2)
    {
        return v1[0] + v1[1] < v2[0] + v2[1];
    };

    sort(scores.begin() + 1, scores.end(), comp);

    for (int i = 1; i < scores.size(); ++i)
    {
        if (isLower(scores[0], scores[i]))
            return -1;

        else if (isSumLower(scores[i], scores[0]))
        {
            removes[i] = true;
            continue;
        }


        for (auto it = upper_bound(scores.begin() + i, scores.end(), scores[i]); it != scores.end(); ++it)
        {
            if (isLower(scores[i], *it))
            {
                removes[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < scores.size(); ++i)
    {
        if (removes[i]) continue;

        sums.emplace_back(scores[i][0] + scores[i][1]);
    }

    sort(sums.rbegin(), sums.rend() - 1);

    return distance(sums.begin(), lower_bound(sums.begin() + 1, sums.end(), sums[0], greater<int>()));
}