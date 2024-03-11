#include <bits/stdc++.h>
using namespace std;

int solution(int coin, vector<int> cards)
{
    int answer = 1;
    int n = cards.size();
    int target = n + 1;
    int idx = n / 3;

    set<int> hand(cards.begin(), cards.begin() + idx);
    set<int> draw;

    auto find_next = [&](auto& s1, auto& s2) -> bool
    {
        for (auto& num : s1)
        {
            auto t = target - num;

            if (s2.end() != s2.find(t))
            {
                s1.erase(num);
                s2.erase(t);

                return true;
            }
        }

        return false;
    };

    while (idx < n)
    {
        draw.insert(cards[idx++]);
        draw.insert(cards[idx++]);

        if (2 <= hand.size() && find_next(hand, hand)) ++answer;
        else if (1 <= hand.size() && 1 <= coin && find_next(hand, draw)) --coin, ++answer;
        else if (2 <= coin && find_next(draw, draw)) coin -= 2, ++answer;
        else break;
    }

    return answer;
}