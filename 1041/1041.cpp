// 1041.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

long long N;
int Dice[7];
long long DiceShowingFace[4];
long long ans;

void sol()
{
    DiceShowingFace[1] = (N - 2) * (5 * N - 6);
    DiceShowingFace[2] = 8 * N - 12;
    DiceShowingFace[3] = 4;
    
    ans += DiceShowingFace[1] * Dice[1];
    ans += DiceShowingFace[2] * (Dice[1] + Dice[2]);
    ans += DiceShowingFace[3] * (Dice[1] + Dice[2] + Dice[3]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= 6; i++)
    {
        cin >> Dice[i];
    }

    sort(Dice, Dice + 7);

    if (N == 1) 
    {
        for (int i = 1; i <= 5; i++)
            ans += Dice[i];

        cout << ans;
    }
    else 
    {
        sol();
        cout << ans;
    }
}