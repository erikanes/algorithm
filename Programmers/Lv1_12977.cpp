#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<bool> vb(3001, true);
    
    for (int i = 2; i <= sqrt(3000); ++i)
        if (vb[i])
            for (int j = i+i; j <= 3000; j += i)
                vb[j] = false;
    
    for (int i = 0; i < nums.size(); ++i)
        for (int j = i+1; j < nums.size(); ++j)
            for (int k = j+1; k < nums.size(); ++k)
                if (vb[nums[i]+nums[j]+nums[k]]) ++answer;
    
    return answer;
}