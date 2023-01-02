#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    vector<int> answer;
    transform(a.begin(), a.end(), b.begin(), back_inserter(answer), [](int v1, int v2) { return v1*v2; });
    return accumulate(answer.begin(), answer.end(), 0);
}


/* 다른 사람의 더 단순한 코드 */
/* <numeric>에 inner_product가 있었지.. */

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {    
    return inner_product(a.begin(),a.end(),b.begin(),0);
}