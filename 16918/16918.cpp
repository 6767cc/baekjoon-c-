// 16918.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

class BOOM
{
private:
    char MAP; // 폭탄 위치 
    int Timelimit;//설치 후 지난시간 3초가 될 경우 burst로

public:
    //초기화
    void InitBOOM(char B, int timelimit)
    {
        MAP = B;
        Timelimit = timelimit;
    }

    char ISMAP()
    {
        return MAP;
    }

    int IsTimelimit()
    {
        return Timelimit;
    }

    void EvenSecond()
    {
        MAP = 'O';
    }

    //2n+1초 경우 (n이 1이상 일때) 2n-1에서 
    void burst()
    {
        MAP = '.';
        Timelimit = 0;
    }

    //시간만 지나감
    void timepass()
    {
        Timelimit++;
    }
};

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, N, time = 0;
    char map[201][201];

    int x[4] = { 1, 0, -1, 0 };
    int y[4] = { 0, 1, 0, -1 };

    vector<pair<int, int>> boomlist;

    BOOM boom[201][201];

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'O')
            {
                boom[i][j].InitBOOM(map[i][j], 0);
            }
            else
            {
                boom[i][j].InitBOOM(map[i][j], 0);
            }
        }
    }


    //N이 2이상 일때만 반복 시작
    while (time++ < N)
    {
        if (time == 0) continue;
        if (time == 1)
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (boom[i][j].ISMAP() == 'O')
                        boom[i][j].timepass();
                }
            }
            continue;
        }

        //짝수 초 일때
        if (time % 2 == 0)
        {
            //폭탄 있던 곳은 시간만 지나가기, 없던곳은 설치하면서 시간을 0으로 초기화
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (boom[i][j].ISMAP() == '.') boom[i][j].EvenSecond();
                    else boom[i][j].timepass();
                }
            }
        }
        //홀수 초 일때
        else
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    //현재 2초면 터져야될 것들, 그보다 작으면 시간만 흐르기
                    if (boom[i][j].IsTimelimit() == 2)
                    {
                        pair<int, int> c = pair<int, int>(i, j);
                        boomlist.push_back(c);
                    }
                    else boom[i][j].timepass();
                }
            }
            //저장한 위치 폭탄 터트리기
            for (auto a : boomlist)
            {
                boom[a.first][a.second].burst();

                //해당위치에서 십자가로 burst
                for (int f = 0; f < 4; f++)
                {
                    int xx = a.first + x[f];
                    int yy = a.second + y[f];

                    //구간 벗어난경우
                    if (xx < 0 || yy < 0 || xx >= R || yy >= C) continue;

                    //터지기
                    if (boom[xx][yy].ISMAP() != '.' || boom[xx][yy].IsTimelimit() != 0) boom[xx][yy].burst();
                }
            }
            boomlist.clear();
        }
    }

    //출력
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << boom[i][j].ISMAP();
        }
        cout << endl;
    }

    return 0;
}