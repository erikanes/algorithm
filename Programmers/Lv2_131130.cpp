#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) {
    multiset<int, greater<>> s;
    vector<bool> b(101, false);

    for (auto& card : cards) {
        auto i = card, c = 0;
        while (!b[i]) {
            b[i] = true;
            i = cards[i-1];
            c++;
        }
        if (c > 0) s.insert(c);
    }

    int i = s.size() >= 2 ? *++s.begin() : 0;
    return *s.begin() * i;
}