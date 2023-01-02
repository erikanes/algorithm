#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < absolutes.size(); ++i)
        answer += absolutes[i] && signs[i] ? absolutes[i] : -absolutes[i];
    return answer;
}