#include <bits/stdc++.h>
using namespace std;

int N;
int S[21][21];
int answer = 0x3f3f3f3f;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	int halfN = N / 2;
	vector<int> v(N, 0);
	fill(v.begin() + halfN, v.end(), 1);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) cin >> S[i][j];

	do
	{
		int start = 0, link = 0;

		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (v[i] != v[j]) continue;
				else if (v[i] + v[j]) start += S[i][j] + S[j][i];
				else link += S[i][j] + S[j][i];
			}
		}

		answer = min(answer, abs(start - link));
	} while (next_permutation(v.begin(), v.end()) && answer);

	cout << answer;

	return 0;
}