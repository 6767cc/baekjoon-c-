// 1012.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<memory.h>

using namespace std;

int Map[51][51];
bool Ch[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int Test;
int M, N, K;
int ans;

vector<int> Ans;

void DFS(int X, int Y)
{
    Ch[X][Y] = true;

    for (int a = 0; a < 4; a++)
    {
        int nx = X + dx[a];
        int ny = Y + dy[a];

        if (nx < 0 || ny < 0 || nx >= M || ny > N) continue;
        if (Map[nx][ny] == 0) continue;
        if (Ch[nx][ny]) continue;

        DFS(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Test;

    for (int i = 0; i < Test; i++)
    {
        memset(Map, 0, sizeof(Map));
        memset(Ch, false, sizeof(Ch));
        ans = 0;

        cin >> M >> N >> K;
        for(int j = 0; j < K; j++)
            {
                int x, y;
                cin >> x >> y;
                
                Map[x][y] = 1;
            }

        for (int j = 0; j < M; j++)
            for (int r = 0; r < N; r++)
            {
                if (Map[j][r] == 1 && !Ch[j][r])
                {
                    DFS(j, r);
                    ans++;
                }
            }
        Ans.push_back(ans);
    }

    for (int A : Ans)
    {
        cout << A << "\n";
    }
}