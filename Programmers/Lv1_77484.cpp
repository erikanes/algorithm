#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 7);
    int zero = count(lottos.begin(), lottos.end(), 0);

    for (auto num : win_nums) {
        if (find(lottos.begin(), lottos.end(), num) != lottos.end()) answer[0]--, answer[1]--;
    }

    answer[0] = answer[0]-zero < 7 ? answer[0]-zero : 6;
    answer[1] = answer[1] < 7 ? answer[1] : 6;

    return answer;
}