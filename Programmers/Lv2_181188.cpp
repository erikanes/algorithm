#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int c = 0x3f3f3f3f;
    int answer = 0;

    sort(targets.begin(), targets.end(), [](auto& l, auto& r) { return l[0] > r[0];});

    for (auto& target : targets)
    {
        if (c >= target[1])
        {
            ++answer;
            c = target[0];
        }
    }

    return answer;
}