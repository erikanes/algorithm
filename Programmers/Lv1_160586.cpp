#include <bits/stdc++.h>
using namespace std;

int calc(map<char,int>& m, string& str) {
    int ans = 0;

    for (int i = 0; i < str.length(); ++i) {
            if (m.find(str[i]) == m.end())
                return -1;
        ans += m[str[i]];
    }
    return ans;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    map<char,int> m;
    vector<int> answer;

    for (auto k : keymap) {
        for (int i = 0; i < k.length(); ++i) {
            if (m.find(k[i]) != m.end())
                m[k[i]] = m[k[i]] > i+1 ? i+1 : m[k[i]];
            else
                 m[k[i]] = i+1;
        }
    }

    for (auto t : targets)
        answer.push_back(calc(m, t));

    return answer;
}