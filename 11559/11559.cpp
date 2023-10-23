// 11559.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

char MAP[12][6];
bool Ch[12][6];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool explode;
int Puyo_Cnt;
int Answer = 0;

vector<pair<int, int>> PuyoPoint, BoomPoint;

void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if (MAP[nx][ny] == '.') continue;
        if (Ch[nx][ny] == true) continue;
        if (MAP[x][y] != MAP[nx][ny]) continue;

        Puyo_Cnt++;
        Ch[nx][ny] = true;
        PuyoPoint.push_back(make_pair(nx, ny));
        DFS(nx, ny);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> MAP[i][j];
        }
    }

    while (true)
    {
        explode = false;
        memset(Ch, false, sizeof(Ch));
        BoomPoint.clear();

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP[i][j] != '.' && Ch[i][j] == false)
                {
                    Puyo_Cnt = 1;
                    PuyoPoint.push_back(make_pair(i, j));
                    Ch[i][j] = true;
                    DFS(i, j);

                    //4개 이상이면 터짐
                    if (Puyo_Cnt >= 4)
                    {
                        explode = true;
                        for (int i = 0; i < PuyoPoint.size(); i++)
                        {
                            BoomPoint.push_back(PuyoPoint[i]);
                        }
                    }
                    PuyoPoint.clear();
                }
            }
        }

        //터졌을 경우 빈공간으로 만들기
        for (int i = 0; i < BoomPoint.size(); i++)
        {
            int x = BoomPoint[i].first;
            int y = BoomPoint[i].second;

            MAP[x][y] = '.';
        }

        //빈 공간 떨어트리기
        for (int i = 10; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP[i][j] == '.') continue;
                int Tmp = i;

                while (1)
                {
                    if (Tmp == 11 || MAP[Tmp + 1][j] != '.') break;

                    MAP[Tmp + 1][j] = MAP[Tmp][j];
                    MAP[Tmp][j] = '.';
                    Tmp++;
                }
            }
        }
        if (explode == true) Answer++;
        else break;
    }

    cout << Answer;
}