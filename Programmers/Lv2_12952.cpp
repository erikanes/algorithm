#include <bits/stdc++.h>

using namespace std;

bool used[3][40];
int answer = 0;

void func(int _n, int _cur)
{
    if (_n == _cur)
    {
        answer++;
        return;
    }

    for (int i = 0; i < _n; ++i)
    {
        if (used[0][i] || used[1][i + _cur] || used[2][_cur - i + _n - 1])
            continue;

        used[0][i] = true;
        used[1][i + _cur] = true;
        used[2][_cur - i + _n - 1] = true;

        func(_n, _cur + 1);

        used[0][i] = false;
        used[1][i + _cur] = false;
        used[2][_cur - i + _n - 1] = false;
    }
}

int solution(int n)
{
    func(n, 0);
    return answer;
}