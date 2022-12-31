#include <bits/stdc++.h>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    auto func = [](auto v) { 
        int c = 0;
        for(int i = 1; i*i <= v; ++i) {
            if (i*i == v) c++;
            else if (v%i == 0) c += 2;
        }
        return c;
    };

    while (left <= right) {
        if (func(left)%2 == 0) answer += left;
        else answer -= left;
        left++;
    }

    return answer;
}


/* 다른 사람의 더 짧은 풀이 */
int sign(int n, int count = 1) {
    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
    return count & 1 ? -1 : 1;
}
int solution(int a, int b) { return a > b ? 0 : sign(a)*a + solution(a + 1, b); }