// 1026.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int arr1[50];//A배열
    int arr2[50];//B참고배열
    int arr3[50];//B고정배열
    int N, M;
    int s = 0;

    scanf("%d", &N); // 배열 길이

    for (int a = 0; a < N; a++)// 1번배열
    {
        scanf("%d", &M);
        arr1[a] = M;
    }

    for (int a = 0; a < N; a++) // 2번 배열
    {
        scanf("%d", &M);
        arr2[a] = M;
        arr3[a] = M;
    }

    sort(arr1, arr1 + N);
    sort(arr2, arr2 + N, greater<int>());

    for (int a = 0; a < N; a++) s += arr1[a] * arr2[a];

    printf("%d", s);
}