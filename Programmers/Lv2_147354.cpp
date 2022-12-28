#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;
	auto func1 = [col](const auto &a, const auto &b) {
		if (a[col-1] != b[col-1]) return a[col-1] < b[col-1];
		else return a[0] > b[0];
	};
	
	sort(data.begin(), data.end(), func1);

	for (int i = row_begin - 1; i < row_end; ++i) {
        auto func2 = [i](int a, int b) { return a + b % (i+1); };
		answer ^= accumulate(data[i].begin(), data[i].end(), 0, func2);
	}
	return answer;
}