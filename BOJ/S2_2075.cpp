#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n * n; ++i) {
        int t;
        cin >> t;
        if (q.size() < n)
            q.emplace(t);
        else {
            if (q.top() < t) {
                q.pop();
                q.emplace(t);
            }
        }
    }

    cout << q.top();

    return 0;
}