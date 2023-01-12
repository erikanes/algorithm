#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int arr[10][10];
    int answer = -1;
    int idx_x, idx_y;
    
    for (int y = 1; y < 10; ++y) {
        for (int x = 1; x < 10; ++x) {
            cin >> arr[y][x];
            if (arr[y][x] > answer) {
                answer = arr[y][x];
                idx_x = x;
                idx_y = y;
            }
        }
    }
    cout << answer << '\n';
    cout << idx_y << ' ' << idx_x;
    
    return 0;
}