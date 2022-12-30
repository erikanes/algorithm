#include <bits/stdc++.h>
using namespace std;

int solution(int storey) {
    vector<int> v;
    int answer = 0;

    while (storey != 0) {
        v.push_back(storey % 10);
        storey /= 10;
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 5) {
            answer += 10 - v[i];
            // 마지막 자릿수 체크
            if (i+1 == v.size()) answer++;
            else v[i+1]++;
        }
        else if (i+1 < v.size() && v[i] == 5 && v[i+1] >= 5) {
        // 595->10을 생각하면 됨
            answer += v[i];
            v[i+1]++;
        }
        else {
            answer += v[i];
        }
    }

    return answer;            
}


/* 다른 사람의 더 간단한 풀이 */
#include<algorithm>

using namespace std;

int sol(int num) {
    if(num < 10) return min(num, 10-num+1);
    int a = num % 10, b = 10 - num % 10;
    return min(sol((num-a)/10)+a, sol((num+b)/10)+b);
}

int solution(int storey) {
    return sol(storey);
}