#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());

    auto ix = X.begin();
    auto iy = Y.begin();

    while (ix != X.end() && iy != Y.end()) {
        if (*ix == *iy) {
            answer.push_back(*ix);
            ix++, iy++;
        }
        else if (*ix > *iy) ix++;
        else iy++;
    }
    if (answer.empty()) answer = "-1";
    else if (*answer.begin() == *answer.rbegin() && *answer.begin() == '0') answer = "0";

    return answer;
}