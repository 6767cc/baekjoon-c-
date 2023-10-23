// 11724.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool Point[1001];

vector<int> map[1001];

void dfs(int n)
{
	Point[n] = true;
	for (int i = 0; i < map[n].size(); i++)
	{
		int NextPoint = map[n][i];
		if (!Point[NextPoint])
		{
			dfs(NextPoint);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int PointA, PointB;
		cin >> PointA >> PointB;

		map[PointA].push_back(PointB);
		map[PointB].push_back(PointA);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!Point[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans;
}
