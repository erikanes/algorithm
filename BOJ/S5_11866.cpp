#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);

    int idx = 0;
    cout << '<';
    while (1) {
        if (++idx == k) {
            cout << q.front();
            q.pop();
            idx = 0;
        }
        else {
            q.push(q.front());
            q.pop();
            continue;
        }

        if (q.empty()) break;
        cout << ", ";
    }
    cout << '>';

    return 0;
}