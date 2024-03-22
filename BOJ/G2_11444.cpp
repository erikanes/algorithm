#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/*
문제 해결 팁
- 피보나치 수열은 아래와 같은 행렬식으로도 구할 수 있다
[0	1]^n	=	[Fn-1	Fn]
[1	1]			[Fn		Fn+1]

단순 행렬 연산으로는 O(N)이 나오지만 거듭제곱의 분할정복을 이용하면 O(logN)으로 구할 수 있다
*/

using ll = long long;
constexpr ll MOD = 1000000007;

class Matrix
{
public:
	Matrix() = default;
	Matrix(ll _11, ll _12, ll _21, ll _22)
	{
		m[0] = _11 % MOD; m[1] = _12 % MOD;
		m[2] = _21 % MOD; m[3] = _22 % MOD;
	}
	Matrix operator*(const Matrix& r)
	{
		return Matrix(m[0] * r.m[0] + m[1] * r.m[2], m[0] * r.m[1] + m[1] * r.m[3],
			m[2] * r.m[0] + m[3] * r.m[2], m[2] * r.m[1] + m[3] * r.m[3]);
	}
	Matrix operator^(long long n)
	{
		auto& M = *this;

		if (n > 1)
		{
			M = M ^ (n / 2);
			M = M * M;

			if (n & 1)
				M = M * Matrix();
		}

		return M;
	}

	ll m[4] = { 0, 1, 1, 1 };
};

int main()
{
	FASTIO;

	ll n;
	cin >> n;

	cout << (Matrix() ^ n).m[1] << '\n';

	return 0;
}