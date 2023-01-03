#include <bits/stdc++.h>
using namespace std;

bool solution(int x) {
    int y = x, z = 0;
    while (x > 0) z += x % 10, x /= 10;
    return y%z == 0;
}