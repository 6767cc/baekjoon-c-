// 1149.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	//집의 색 가격(최대 1000개 까지)
	int arr2[1000][3];

	// 집의 수,  결과
	int n, answer;

	//집 갯수 받기
	scanf("%d", &n);

	//집 색 당 가격
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr2[i][j]);

	// 연산
	for (int i = 1;i < n;i++)
	{
		arr2[i][0] = arr2[i][0] + min(arr2[i - 1][1], arr2[i - 1][2]);
		arr2[i][1] = arr2[i][1] + min(arr2[i - 1][0], arr2[i - 1][2]);
		arr2[i][2] = arr2[i][2] + min(arr2[i - 1][0], arr2[i - 1][1]);
	}

	answer = min({ arr2[n - 1][0],arr2[n - 1][1],arr2[n - 1][2] });

	printf("%d", answer);

	return 0;
}