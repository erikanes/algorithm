#include <bits/stdc++.h>
using namespace std;
const int INF = static_cast<int>(1e8);

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; ++i) v[i][i] = 0;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
        v[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
		}
	}

	int cm = INF, ans = 0;

	for (int i = 1; i <= n; ++i)
	{
		int t = min(cm, accumulate(v[i].begin() + 1, v[i].end(), 0));
		if (t < cm) cm = t, ans = i;
	}

	cout << ans;
	
	return 0;
}