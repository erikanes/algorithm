#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<>());
    int answer = 0;
    for (auto i = score.begin(); score.size() - distance(score.begin(), i) >= m; i += m) {
        answer += *(i+m-1) * m;
    }

    return answer;
}