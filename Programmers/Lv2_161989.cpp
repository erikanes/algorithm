#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    auto it = section.begin();
    int answer = 0;

    while (it != section.end()) {
        auto prev = it;
        it = lower_bound(it, section.end(), *it+m);
        if (prev == it) ++it;
        else ++answer;
    }
    return answer;
}