#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    auto clamp = [k](int value)->int {
        return int(value >= k ? k - 1 : value);
    };
    vector<int> answer;

    for (int i = 0; i < score.size(); ++i) {
        sort(score.begin(), score.begin()+i+1, greater<>());
        answer.push_back(score[clamp(i)]);
    }

    return answer;    
}