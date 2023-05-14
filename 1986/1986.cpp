// 1986.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int N, M, MAP[1010][1010], dis[1010][1010];

int QN, KN, PN;

int Qx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int Qy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int Kx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int Ky[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void set()
{
    cin >> N >> M;

    //퀸 = 1
    cin >> QN;
    for (int i = 1; i <= QN; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
    }

    //나이트 = 2
    cin >> KN;
    for (int i = 1; i <= KN; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 2;
    }

    //폰 = 3 
    cin >> PN;
    for (int i = 1; i <= PN; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 3;
    }
}

// 경우 : 퀸
void Q(int a, int b)
{
    for (int i = 0; i < 8; i++)
    {
        int xx = a + Qx[i];
        int yy = b + Qy[i];

        while (1)
        {
            if (xx < 1 || yy < 1 || xx > N || yy > M) break;

            if (MAP[xx][yy] != 0) break;

            dis[xx][yy] = 1;
            xx = xx + Qx[i];
            yy = yy + Qy[i];
        }
    }
}

// 경우 : 잭
void K(int a, int b)
{

    for (int i = 0; i < 8; i++)
    {
        int xx = a + Kx[i];
        int yy = b + Ky[i];

        if (xx < 1 || yy < 1 || xx > N || yy > M) continue;
        else if (dis[xx][yy] == 0) dis[xx][yy] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    //말 놓기
    set();

    //체크하기
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] == 0) continue;

            if (MAP[i][j] == 1)
            {
                dis[i][j] = 1;
                Q(i, j);
            }

            if (MAP[i][j] == 2)
            {
                dis[i][j] = 1;
                K(i, j);
            }

            if (MAP[i][j] == 3)
            {
                dis[i][j] = 1;
            }

        }
    }

    //값 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (dis[i][j] == 0) ans++;
        }
    }
    printf("%d", ans);
}