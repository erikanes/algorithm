#include <bits/stdc++.h>
using namespace std;

const int bx[4] = { 1, 0, 0, -1 };
const int by[4] = { 0, -1, 1, 0 };
const char* dir = "dlru";

#define bit_abs(_x_) (_x_ & 0x80000000 ? -(_x_) : (_x_))

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer;
    answer.resize(k);

    int dist = bit_abs(r - x) + bit_abs(c - y);

    if (k < dist || (k - dist) % 2) return "impossible";

    auto dfs = [&](auto& self, int sx, int sy, int cnt) -> bool
    {
        if (cnt == k)
        {
            if (r == sx && c == sy) return true;
            return false;
        }

        for (int i = 0; i < 4; ++i)
        {
            int dx = sx + bx[i];
            int dy = sy + by[i];
            dist = bit_abs(r - dx) + bit_abs(c - dy);

            if (dx <= 0 || dx > n || dy <= 0 || dy > m) continue;
            else if (k - cnt < dist) continue;

            answer[cnt] = dir[i];

            if (self(self, dx, dy, cnt + 1)) return true;
        }

        return false;
    };

    dfs(dfs, x, y, 0);

    return answer;
}

/*
dfs 또는 그리디로 풀 수 있는 문제
그리디로 푸는 경우 식을 잘 세우면 O(1)로 풀이가 가능하다고 함
dfs는 탐색 중단 조건을 잘 설정해야 시간초과가 나지 않음
조건 없이 완전탐색시 O(4^k)에 가까워진다
*/