// 14889.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

void input(int N, int arr[20][20])
{
    int n;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> n;
            arr[i][j] = n;
        }
    }
}

void sol(int N, int arr[20][20])
{

    //
}

int main()
{
    int N;
    int Member[20][20];

    cin >> N;

    input(N, Member);
    sol(N, Member);
}