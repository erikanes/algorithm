#include <bits/stdc++.h>
using namespace std;

bool visited[8];
int answer = 0;

void backtracking(int k, vector<vector<int>>& v, int n) {
    for (int i = 0; i < v.size(); ++i) {
        if (k >= v[i][0] && !visited[i]) {
            visited[i] = true;
            backtracking(k-v[i][1], v, n+1);
            visited[i] = false;
        }
    }
    answer = max(answer, n);
}

int solution(int k, vector<vector<int>> dungeons) {
    backtracking(k, dungeons, 0);
    return answer;
}