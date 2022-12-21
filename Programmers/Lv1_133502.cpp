#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class func {
public:
    func() : ans(0) {
        v.reserve(1000001);
        v.assign(1, 0);
    }
    void operator()(const int& i) {
        if (*(v.rbegin())%3+1 == i) { // 1, 2, 3, 1, ...
            v.push_back(i);
            if (v.size() < 4 || i != 1) return; // 1, 1, 2, 3 방지를 위해 i != 1
            if (accumulate(v.rbegin(), v.rbegin()+4, 0) != 7) return; // 누적합
            v.erase(v.end()-4, v.end()); // 삭제
            ans++;
        }
        else if (i == 1) v.push_back(i);
        else v.assign(1, 0);    
    }
    inline int result() { return ans; }
private:
    vector<int> v;
    int ans;
};

int solution(vector<int> ingredient) {
    // for_each는 사용한 함수 객체를 반환한다
    return for_each(ingredient.begin(), ingredient.end(), func()).result();
}




/* 더 심플한 다른 사람의 코드 */
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }    

    return answer;
}