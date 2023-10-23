// 14889.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int N;
int Member[21][21];
bool Ch[21];
int ans = 0xfffffff;

void sol(int C, int pos);
{
	if (x == N / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		int StartPoint = 0;
		int LinkPoint = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (Ch[i] == true && Ch[j] == true) StartPoint += Mumber[i][j];
				if (Ch[i] == false && Ch[j] == false) LinkPoint += Mumber[i][j];
			}
		}

		int abs;
		if (StartPoint > LinkPoint) abs = StartPoint - LinkPoint;
		else abs = LinkPoint - StartPoint;

		if (ans > abs) ans = abs;

	}

	for (int i = pos; i < N; i++)
	{
		Ch[i] = true;
		DFS(C + 1, i + 1);
		Ch[i] = false;
	}
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> Member[i][j];
        }
    }

    sol(0, 1);

    cout << ans;
}