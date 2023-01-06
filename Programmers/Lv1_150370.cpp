#include <bits/stdc++.h>
using namespace std;

bool isExpired(int today, int term, string privacy) {
    int y = stoi(privacy.substr(0, 4));
    int m = stoi(privacy.substr(5, 2));
    int d = stoi(privacy.substr(8, 2));

    return today > y*336 + (m+term)*28 + d-1;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    map<char, int> m;
    for (auto& term : terms)
        m[term.front()] = stoi(string(term.begin()+2, term.end()));

    vector<int> answer;
    int t = stoi(today.substr(0, 4))*336 + stoi(today.substr(5, 2))*28 + stoi(today.substr(8, 2));

    for (int i = 0; i < privacies.size(); ++i)
        if (isExpired(t, m[privacies[i].back()], privacies[i])) answer.push_back(i+1);

    return answer;
}