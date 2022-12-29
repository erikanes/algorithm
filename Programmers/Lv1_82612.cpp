long long solution(int price, int money, int count)
{ 
    long long answer = (count * (1+count) / 2) * (long long)price - money;
    return answer < 0 ? 0 : answer;
}