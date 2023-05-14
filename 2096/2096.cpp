// 2096.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001][3];

void input()
{
    int a, b, c;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        arr[i][0] = a; arr[i][1] = b; arr[i][2] = c;
    }
}

void sol() // 맥스값만
{
    int Max0, Max1, Max2; // 최댓값
    int Min0, Min1, Min2; // 최솟값

    int a, b, c; // 잠시 저장용

    Max0 = arr[0][0]; Max1 = arr[0][1]; Max2 = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        a = max(Max0, Max1) + arr[i][0];
        b = max({ Max0, Max1, Max2 }) + arr[i][1];
        c = max(Max1, Max2) + arr[i][2];

        Max0 = a;
        Max1 = b;
        Max2 = c;
    }

    Min0 = arr[0][0]; Min1 = arr[0][1]; Min2 = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        a = min(Min0, Min1) + arr[i][0];
        b = min({ Min0, Min1, Min2 }) + arr[i][1];
        c = min(Min1, Min2) + arr[i][2];

        Min0 = a;
        Min1 = b;
        Min2 = c;
    }

    cout << max({ Max0, Max1, Max2 }) << " " << min({ Min0, Min1, Min2 });
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    sol();
}