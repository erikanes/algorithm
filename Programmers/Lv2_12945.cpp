#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int f[100001] = {0, 1};
    
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i-2] + f[i-1]) % 1234567;
    
    return f[n];
}