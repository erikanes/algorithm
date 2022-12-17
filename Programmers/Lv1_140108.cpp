#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int f = 0;
	auto it = s.begin();

	for (auto i = s.begin(); i != s.end(); ++i) {
		if (i == it) {
			++f;
			continue;
		}
		*i == *it ? ++f : --f;
		if (f == 0) {
			++answer;
			it = i + 1;
		}
	}
	return f > 0 ? answer + 1 : answer;
}