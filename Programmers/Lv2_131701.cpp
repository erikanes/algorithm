/* 총 루프1개, 구간합 루프2개 = 3개 */
/* 다른 사람 코드처럼 set의 중복값 불허를 이용하면 루프 2개로 줄일 수 있음 */

#include <bits/stdc++.h>
using namespace std;

set<int> answer;

int solution(vector<int> elements) {
    const int sz = elements.size();

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            int sum = 0;
            for (int k = j; k < i+j+1; ++k) {
                sum += elements[k%sz];
            }
            answer.insert(sum);
        }
    }

    return answer.size();
}


/* 다른 사람의 더 심플한 풀이 */
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0 ; i < n ; ++i) {
        int sum = 0;
        for (int j = i ; j < i + n ; ++j) {
            sum += elements[j % n]; // 어차피 중복값은 날아감
            S.insert(sum);
        }
    }

    return S.size();
}