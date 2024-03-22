#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

string formula;
stack<char> operators;

/*
풀이 핵심
- 알파벳은 그냥 출력
- +, -는 여는 괄호 또는 우선순위가 같거나 높은 연산자(=모든 연산자)를 만날때까지 스택을 출력한 뒤에 push
- *, /는 top이 우선순위가 낮은 연산자(=+, -)를 만날때까지 스택을 출력한 뒤에 push
- 여는 괄호는 바로 push
- 닫는 괄호는 여는 괄호를 만날때까지 스택을 출력
- 마지막으로 스택이 빌때까지 출력
*/

bool ispm(const char& c)
{
	return c == '+' || c == '-';
}

bool ismd(const char& c)
{
	return c == '*' || c == '/';
}

int main()
{
	FASTIO;

	cin >> formula;

	auto print = [&]() { cout << operators.top(); operators.pop(); };

	for (auto& c : formula)
	{
		if (isalpha(c))
			cout << c;

		else if (ispm(c))
		{
			while (!operators.empty() && '(' != operators.top())
				print();
			operators.push(c);
		}

		else if (ismd(c))
		{
			while (!operators.empty() && ismd(operators.top()))
				print();
			operators.push(c);
		}

		else if ('(' == c)
			operators.push(c);

		else if (')' == c)
		{
			while ('(' != operators.top())
				print();
			operators.pop();
		}
	}

	while (!operators.empty())
		print();

	return 0;
}