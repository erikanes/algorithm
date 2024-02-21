#include <bits/stdc++.h>

/*
원의 방정식과 예외를 고려해서 풀어야 하는 문제
완벽하게 혼자 푼 문제가 아니기 때문에 복기해봐야 한다
*/

using namespace std;
using ll = long long;

long long solution(int r1, int r2)
{
    ll answer = 0;
    ll r1_ = (ll)r1 * r1;
    ll r2_ = (ll)r2 * r2;

    for (ll x = 1; x <= r2; ++x)
    {
        ll y1 = ceil(sqrt(r1_ - x * x));
        ll y2 = floor(sqrt(r2_ - x * x));
        answer += y2 - y1 + 1;
    }

    return 0;
}