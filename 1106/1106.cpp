// 1106.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>

using namespace std;

int info[20][2]; // 집 정보 
int sum[1001]; // 인원 당 최소합

int advertisement(int customer, int cityNum)
{
	int Min = 100000;
	int cost;

	if (customer <= 0) return 0;
	else if (sum[customer] > 0) return sum[customer]; // 이전에 계산했다면
	else
	{
		for (int i = 0; i < cityNum; i++)
		{
			cost = advertisement(customer - info[i][1], cityNum) + info[i][0];
			Min = min(cost, Min);
		}
		sum[customer] = Min;

		return Min;
	}
}

int main()
{
	int c, n;

	cin >> c >> n;

	for (int i = 0; i < n; i++)
		cin >> info[i][0] >> info[i][1];

	cout << advertisement(c, n);
}