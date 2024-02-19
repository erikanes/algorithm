/*
대칭 시켜서 풀면 간단히 풀 수 있는 문제
*/

#include <bits/stdc++.h>

using namespace std;

int pow(int n)
{
    return n * n;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer(balls.size(), 1e9);

    for (int i = 0; i < balls.size(); ++i)
    {
        int bx = balls[i][0], by = balls[i][1];

        // 좌 상 우 하
        if (startY != by || startX <= bx)
            answer[i] = min(answer[i], pow(startX + bx) + pow(startY - by));
        if (startX != bx || startY >= by)
            answer[i] = min(answer[i], pow(startX - bx) + pow(2 * n - startY - by));
        if (startY != by || startX >= bx)
            answer[i] = min(answer[i], pow(2 * m - startX - bx) + pow(startY - by));
        if (startX != bx || startY <= by)
            answer[i] = min(answer[i], pow(startX - bx) + pow(startY + by));
    }

    return answer;
}