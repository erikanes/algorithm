#include <bits/stdc++.h>
using namespace std;

unordered_map<char, bool> m;
bitset<4> mbti[32];
char input[5];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T, N;
	cin >> T;

	m['I'] = false; m['N'] = false; m['F'] = false; m['P'] = false;
	m['E'] = true; m['S'] = true; m['T'] = true; m['J'] = true;

	while (T--)
	{
		int answer = 0x3f3f3f3f;
		cin >> N;

		if (N >= 33)
		{
			for (int i = 0; i < N; ++i) cin >> input;

			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < N; ++i)
		{
			cin >> input;
			for (int j = 0; j < 4; ++j) mbti[i].set(j, m[input[j]]);
		}

		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				for (int k = j + 1; k < N; ++k)
				{
					int ab = (mbti[i] ^ mbti[j]).count();
					int bc = (mbti[j] ^ mbti[k]).count();
					int ac = (mbti[i] ^ mbti[k]).count();
					answer = min(answer, ab + bc + ac);
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}