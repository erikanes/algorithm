#include <bits/stdc++.h>
using namespace std;

int convert(const string& time)
{
	int hour = (time[0] - '0') * 600 + (time[1] - '0') * 60;
	int min = (time[3] - '0') * 10 + (time[4] - '0');

	return hour + min;
}

int solution(vector<vector<string>> book_time) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<>> q;
	vector<pair<int, int>> v;
	q.push(0);

	for (auto& times : book_time)
		v.emplace_back(convert(times[0]), convert(times[1]) + 10);

	sort(v.begin(), v.end());

	for (auto& times : v)
	{
		if (q.top() <= times.first)
		{
			q.pop();
			q.push(times.second);
		}
		else
			q.push(times.second);

		answer = max(answer, (int)q.size());
	}

	return answer;
}