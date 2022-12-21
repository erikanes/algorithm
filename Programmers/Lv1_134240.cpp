#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); ++i)
    {
        string t;
        t.assign(food[i]/2, i+'0');
        answer += t;
    }
    string r = answer;
    reverse(r.begin(), r.end());
    
    return answer + '0' + r;
}