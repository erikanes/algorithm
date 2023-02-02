#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int visited[1001];

const int INF = 1e9 + 1;

int bfs(const int n) {
    queue<int> q;

    fill(visited, visited + n, INF);
    visited[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= arr[cur]; ++i) {
            if (cur + i >= n) break;

            if (visited[cur + i] > visited[cur] + 1) {
                visited[cur + i] = visited[cur] + 1;
                q.push(cur + i);
            }
        }
    }

    if (INF == visited[n - 1])
        return -1;
    else
        return visited[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << bfs(n);

    return 0;
}