// 1463.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1000001];

int CA(int n)
{
	if (arr[n] != 0) return arr[n];

	arr[n] = CA(n - 1) + 1;
	if (n % 3 == 0) arr[n] = min(arr[n], CA(n / 3) + 1);
	if (n % 2 == 0) arr[n] = min(arr[n], CA(n / 2) + 1);

	return arr[n];
}

int main()
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int Fn, ans;
	scanf("%d", &Fn);

	if (Fn == 1) ans = 0;
	else ans = CA(Fn);

	printf("%d", ans);

	return 0;
}