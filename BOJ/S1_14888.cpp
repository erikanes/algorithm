#include <bits/stdc++.h>
using namespace std;

int N, A[101], OP[4];
int MIN = 0x3f3f3f3f;
int MAX = -0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    auto backtracking = [&](auto& self, int idx, int result)
    {
        if (idx == N)
        {
            MIN = min(MIN, result);
            MAX = max(MAX, result);
            return;
        }

        for (int j = 0; j < 4; ++j)
        {
            if (0 >= OP[j]) continue;
            --OP[j];
            if (0 == j) self(self, idx + 1, result + A[idx]);
            else if (1 == j) self(self, idx + 1, result - A[idx]);
            else if (2 == j) self(self, idx + 1, result * A[idx]);
            else self(self, idx + 1, result / A[idx]);
            ++OP[j];
        }
    };

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < 4; ++i) cin >> OP[i];
    backtracking(backtracking, 1, A[0]);
    cout << MAX << '\n' << MIN;

    return 0;
}