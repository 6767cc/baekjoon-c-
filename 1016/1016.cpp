// 1016.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

long long Min, Max;
bool arr[1000001];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Min >> Max;
    for (long long i = 2; i * i <= Max; i++)
    {
        long long x = Min / (i * i);
        if (Min % (i * i) != 0) x++;

        while (x * i * i <= Max)
        {
            arr[(x * i * i) - Min] = true;
            x++;
        }
    }

    for (int i = 0; i <= Max - Min; i++)
    {
        if (!arr[i]) ans++;
    }

    cout << ans;
}
