#include <bits/stdc++.h>

using namespace std;
bitset<20> b;

vector<int> solution(string s)
{
    vector<int> answer(2, 0);

    while (1 != s.size())
    {
        int len = count_if(s.begin(), s.end(), [](auto& c) { return c == '1'; });
        ++answer[0];
        answer[1] += s.size() - len;

        b = len;
        string t = b.to_string();
        auto it = find(t.begin(), t.end(), '1');

        s = move(string(it, t.end()));
    }

    return answer;
}