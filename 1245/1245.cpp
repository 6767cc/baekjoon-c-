// 1245.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int Map[101][101];
bool Ch[101][101];

int N, M;
int ans;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

bool peak;

void DFS(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (Map[x][y] < Map[nx][ny]) peak = false;

        if (Ch[nx][ny]) continue;

        if (Map[x][y] == Map[nx][ny])
        {
            Ch[nx][ny] = true;
            DFS(nx, ny);
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i< N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
        }

    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (!Ch[i][j])
            {
                peak = true;
                Ch[i][j] = true;
                DFS(i, j);
                if (peak) ans++;
            }
        }

    cout << ans;
}