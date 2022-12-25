#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    const vector<string> vs = { "RT", "CF", "JM", "AN" };
    map<char, int> m;

    for (int i = 0; i < survey.size(); ++i) {
        if (choices[i] < 4) m[survey[i][0]] += 4 - choices[i];
        else m[survey[i][1]] += choices[i] - 4;
    }   

    for (auto s : vs) {
        if (m[s[0]] >= m[s[1]]) answer.push_back(s[0]);
        else answer.push_back(s[1]);
    }

    return answer;
}