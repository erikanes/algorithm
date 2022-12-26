#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    unordered_map<string, int> idx;
    unordered_map<string, unordered_set<string>> m;

    for (int i = 0; i < id_list.size(); ++i) idx[id_list[i]] = i;

    auto func = [&m](const string& s) {
        auto it = find(s.begin(), s.end(), ' ');
        string s1(s.begin(), it);
        string s2(it, s.end());

        m[s2].insert(s1);
    };

    for_each(report.begin(), report.end(), func);

    for (auto& p : m) {
        if (p.second.size() >= k) {
            for (auto& s : p.second) {
                answer[idx[s]]++;
            }
        }
    } 

    return answer;
}