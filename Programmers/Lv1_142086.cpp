#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int arr[33] = {0,};
	int idx = 1;

	for (auto c : s) {
		int r = -1;
		if (arr[c - 'a' + 1] != 0) r = idx - arr[c - 'a' + 1];
		arr[c - 'a' + 1] = idx++;
		answer.push_back(r);
	}
    return answer;
}