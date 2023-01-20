#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    function<int(int, int)> gcd = [&](auto a, auto b) {
        if (b == 0) return a;
        else return gcd(b, a%b);
    };
    int n, m, t;
    cin >> n >> m;
    
    t = gcd(n, m);
    
    cout << t << '\n' << (n*m) / t;
    
    return 0;
}