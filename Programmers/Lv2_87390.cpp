#include <bits/stdc++.h>
using namespace std;

/* (1,1) = 1, (1,2) = 2, ... */
/* 좌표중 큰값이 해당 원소의 값 */
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while (left <= right) answer.push_back(max(left/n+1, left++%n+1));
    return answer;
}