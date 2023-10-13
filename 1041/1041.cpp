// 1041.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long Dice[6];

long long ans;

long long TopNumber, SumNumber;

long long Min1 = 51, Min2 = 101, Min3 = 151;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        cin >> Dice[i];
        SumNumber += Dice[i];
        TopNumber = max(Dice[i], TopNumber);
    }

    //마주보지 않는 가장 작은 주사위눈 조합 만들기
    for (int i = 0; i < 6; i++)
    {
        Min1 = min(Min1, Dice[i]);
        for (int j = i + 1; j < 6; j++)
        {
            if (i + j == 5) continue;
            Min2 = min(Min2, Dice[i] + Dice[j]);
            
            for (int k = j + 1; k < 6; k++)
            {
                if (i + k == 5 || j + k == 5) continue;
                Min3 = min(Min3, Dice[i] + Dice[j] + Dice[k]);
            }
        }
    }

    if (N == 1) ans = SumNumber - TopNumber;
    else
    {
        ans += ((N - 2) * (5 * N - 6)) * Min1;
        ans += (8 * N - 12) * Min2;
        ans += 4 * Min3;
    }

    cout << ans;
}