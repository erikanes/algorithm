#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    vector<int> v(number.size()-3);
    for(int i = 0; i < 3; ++i) v.push_back(1);

    do {
        int sum = 0;
        for (int i = 0; i < number.size(); ++i)
            if (v[i]) sum += number[i];

        sum == 0 ? ++answer : answer;
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}