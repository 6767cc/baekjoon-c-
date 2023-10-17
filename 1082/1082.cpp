// 1082.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int N, M;
int P[10];

string ans = "";

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    cin >> M;
}

void sol()
{
    int cost = 0;

    while (cost > M)
    {
        for (int i = N - 1; i < 0; i--)
        {

        }
        //길이가 길수록 큰 숫자가 앞에 있을 수록 이득
    }
}

int main()
{
    input();
    if (N == 1) ans += '0';
    else sol();

    cout << ans;
}