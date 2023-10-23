// 2491.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int N;
int Arr[200000];

void sol()
{
    int ans = 1;
    int UpCount = 1;
    int DownCount = 1;

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            if (Arr[i] <= Arr[i + 1]) UpCount++;
            else UpCount = 1;
        }

        if (i < N - 1)
        {
            if (Arr[i] >= Arr[i + 1]) DownCount++;
            else DownCount = 1;
        }

        int TheBiggerOne = max(UpCount, DownCount);
        ans = max(ans, TheBiggerOne);
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0;i < N; i++)
    {
        cin >> Arr[i];
    }

    sol();
}

