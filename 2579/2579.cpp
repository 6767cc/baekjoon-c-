// 2579.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int MP[1000]; // 각 계단 최대 포인트 
int arr[1000]; //각 단당 포인트

void dp()
{
    MP[1] = arr[1];
    MP[2] = arr[1] + arr[2];
    MP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= n; i++)
    {
        MP[i] = max(MP[i - 2], MP[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << MP[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //주는 정보들
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    dp();

    return 0;
}