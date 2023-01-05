#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* 원의 방정식. x²+y²=r² */
long long solution(int k, int d) {
    ll answer = 0;
    for (ll x = 0; x <= d; x += k)
        answer += floor(sqrt(static_cast<ll>(d)*d - x*x)) / k + 1;
    return answer;
}