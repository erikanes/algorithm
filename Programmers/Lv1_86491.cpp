#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;

    for (int i = 0; i < sizes.size(); ++i) {
        int sw = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        int sh = sizes[i][0] < sizes[i][1] ? sizes[i][0] : sizes[i][1];
        w = w > sw ? w : sw;
        h = h > sh ? h : sh;
    }

    return w * h;
}