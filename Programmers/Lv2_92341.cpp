#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> m;
    vector<int> answer;

    for (const auto& r : records) {
        int t = stoi(r.substr(0, 2)) * 60 + stoi(r.substr(3, 2));
        if (r.substr(11, 2) == "IN") m[r.substr(6, 4)] -= t;
        else m[r.substr(6, 4)] += t;
    }

    for (auto& [key, value] : m) {
        if (value <= 0) value += 1439;
        float a = value - fees[0] > 0 ? value - fees[0] : 0;
        int b = ceil(a / fees[2]);

        answer.push_back(fees[1] + b * fees[3]);
    }

    return answer;
}