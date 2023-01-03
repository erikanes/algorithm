#include <bits/stdc++.h>
using namespace std;

string solution(string phone_number) {
    return string(phone_number.size()-4, '*').append(phone_number.end()-4, phone_number.end());
}