#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    int min_val1, min_val2;
    min_val1 = min_val2 = 100001;
    while (m--) {
        int p1, p2;
        cin >> p1 >> p2;
        min_val1 = min(min_val1, p1);
        min_val2 = min(min_val2, p2);
    }

    int answer = min(100001, ((n-1)/6+1) * min_val1);
    answer = min(answer, min_val2 * n);
    answer = min(answer, (n/6*min_val1) + (n%6*min_val2));

    cout << answer;
    return 0;
}