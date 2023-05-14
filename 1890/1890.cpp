// 1890.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int i, j, N;
int map[1020][1020];
long long ans[1020][1020];

void sol()
{
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (ans[i][j] == 0) continue;
                if (i == N - 1 && j == N - 1) continue;

                long long DR = map[i][j] + i; // 내려가는 루트
                long long RR = map[i][j] + j; // 오른쪽 루트

                if (DR < N) ans[DR][j] = ans[DR][j] + ans[i][j];
                if (RR < N) ans[i][RR] = ans[i][RR] + ans[i][j];
            }
        }
    }
}

int main()
{
    cin >> N;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            cin >> map[i][j];

    ans[0][0] = 1;
    sol();

    cout << ans[N - 1][N - 1];
}