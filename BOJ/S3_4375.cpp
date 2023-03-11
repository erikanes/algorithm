#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n) {
        int i = 1, l = 1;
        while (l%n) {
            l = l * 10 + 1;
            l %= n;
            ++i;
        }
        cout << i << '\n';
    }
    
    return 0;
}