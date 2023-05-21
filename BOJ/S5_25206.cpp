#include <bits/stdc++.h>
using namespace std;

float getScore(string s)
{
	if (s == "A+") return 4.5f;
	else if (s == "A0") return 4.f;
	else if (s == "B+") return 3.5f;
	else if (s == "B0") return 3.f;
	else if (s == "C+") return 2.5f;
	else if (s == "C0") return 2.f;
	else if (s == "D+") return 1.5f;
	else if (s == "D0") return 1.f;
	else return 0.f;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 0;
	float f1, f2;
	f1 = f2 = 0.f;

	for (int i = 0; i < 20; ++i)
	{
		string subject, grade;
		float f;

		cin >> subject >> f >> grade;
		if (grade == "P")
			continue;
		f1 += f;
		f2 += f * getScore(grade);
	}

	cout << f2 / f1;

	return 0;
}