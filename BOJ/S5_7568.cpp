#include <iostream>
using namespace std;

int arr[52][2];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i][0] >> arr[i][1];

    for (int i = 0; i < n; ++i) {
        int grade = n;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (arr[i][0] >= arr[j][0] || arr[i][1] >= arr[j][1]) grade--;
        }
        cout << grade << ' ';
    }

    return 0;
}