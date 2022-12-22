#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    auto func = [&answer](string s) {
        vector<string> temp = { "aya", "ye", "woo", "ma" };
        auto iter = s.begin();
        int flag = -1;

        while (iter != s.end()) {
            int count = 0;
            for (int i = 0; i < temp.size(); ++i) {
                auto it = search(iter, s.end(), temp[i].begin(), temp[i].end());
                if (it == iter && i != flag) {
                    iter += temp[i].size();
                    flag = i;
                    break;
                }
                count++;
            }
            if (count == 4) return;
        }
        answer++;
        return;
    };

    for_each(babbling.begin(), babbling.end(), func);        

    return answer;
}




/* 더 심플한 다른 사람의 코드 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer=0;

    for(string s : babbling)
    {
        int flag=0; bool j=true;
        for(int i=0; i<s.length(); i++)
        {
            if(s.substr(i,3)=="aya" && flag!=1) { flag=1; i+=2; }
            else if(s.substr(i,2)=="ma" && flag!=2) { flag=2; i+=1; }
            else if(s.substr(i,3)=="woo" & flag!=3) { flag=3; i+=2; }
            else if(s.substr(i,2)=="ye" && flag!=4) { flag=4; i+=1; }
            else { j=false; break; }
        }
        if(j==true) answer++;
    }

    return answer;
}