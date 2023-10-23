// 13460.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

char map[11][11];
int N, M, ans = 0;

pair<int, int> RadPoint;
pair<int, int> BluePoint;
pair<int, int> GoalPoint;

bool RadBallGoalIn;
bool BlueBallGoalIn;
int x[4] = { -1, 0, 1, 0 };
int y[4] = { 0, -1, 0, 1 };


/*굴러가지 못하는 경우
1. 벽에 부딪힌경우
2. 구멍에 들어가다

잠시 구르는 것을 멈춰야하는 경우
1. 다른색 공을 만났을때(공이 움직인 후 다시 움직일 수 있기 때문에)
*/

void RadBallMove(int Rx, int Ry ,int v)
{
    if (map[Rx][Ry] == '#') return;
    if (map[Rx][Ry] == 'O')
    {
        RadBallGoalIn = true;
        return;
    }
    int dx = RadPoint.first +  x[v];
    int dy = RadPoint.second + y[v];
}

void BlueBallMove(int Bx, int By,int v)
{
    if (map[Bx][By] == '#') return;
    if (map[Bx][By] == 'O')
    {
        BlueBallGoalIn = true;
        return;
    }

    int dx = Bx + x[v];
    int dy = By + y[v];
}

int Fieldtilt(int TiltCount)
{
    if (TiltCount > 10) return -1;

    for (int i = 0; i < 4; i++)
    {
        RadBallMove(RadPoint.first, RadPoint.second, i);
        BlueBallMove(BluePoint.first, BluePoint.second, i);

        if (RadBallGoalIn && !BlueBallGoalIn) cout << TiltCount;
        else
        {
            Fieldtilt(TiltCount + 1);
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'R') RadPoint = pair<int, int>(i, j);
            if (map[i][j] == 'B') BluePoint = pair<int, int>(i, j);
            if (map[i][j] == 'O') GoalPoint = pair<int, int>(i, j);
        }

    Fieldtilt(0);

    if (RadBallGoalIn && !BlueBallGoalIn) cout << ans;
    else cout << -1;
}