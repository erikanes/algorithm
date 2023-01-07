#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> m;
    transform(want.begin(), want.end(), number.begin(), inserter(m, m.end()),
              [](auto a, auto b){ return pair(a, b); });

    int answer = 0;
    for(auto i = discount.begin(); i != discount.end()-9; ++i) {
        int t = 0;
        for (const auto& w : want) if (m[w] == count(i, i+10, w)) t++;
        if (t == want.size()) answer++;
    }
    return answer;
}