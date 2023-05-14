// 15729.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int ans;
bool swi[1000003];

int main()
{
    int N, M;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> M;
        if (M == 1) swi[i] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (swi[i] == true)
        {
            ans++;

            swi[i] = !swi[i];
            swi[i + 1] = !swi[i + 1];
            swi[i + 2] = !swi[i + 2];
        }
    }

    cout << ans;
}