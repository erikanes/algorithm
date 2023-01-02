#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    string s;
    int answer = 0;
    while (n/3 >= 1) {
        s.push_back(n%3+'0');
        n /= 3;
    }
    s.push_back(n+'0');

    int t = 1;
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        answer += (*i-'0') * t;
        t *= 3;
    }
    return answer;
}


/* 다른 사람의 좀 더 나은 코드 */
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n > 0){
        v.push_back(n%3);
        n/=3;
    }
    int k = 1;
    while(!v.empty()) {
        answer += k*v.back();
        v.pop_back();
        k*=3;
    }

    return answer;
}