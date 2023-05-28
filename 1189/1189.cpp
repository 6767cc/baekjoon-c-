// 1189.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int R, C, K;
char map[6][6];
bool ch[6][6];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int ans = 0;

void dfs(int x, int y, int Dep)
{
	if (x == C - 1 && y == 0 && Dep == K)
	{
		ans++;
		return;
	}

	ch[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && yy >= 0 && xx < C && yy < R)
		{
			if (!ch[xx][yy] && map[xx][yy] != 'T')
			{
				dfs(xx, yy, Dep + 1);
			}
		}
	}

	ch[x][y] = false;
}
int main()
{
	cin >> R >> C >> K;

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			cin >> map[i][j];

	dfs(0, R - 1, 1);

	cout << ans;
}
