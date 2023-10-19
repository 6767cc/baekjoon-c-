// 16931.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int N, M;
int map[101][101];
int h = 0, v = 0;
int ans = 0;

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }

    //위아래
    ans += 2 * N * M;


    //정면
    for (int i = 0; i < N; i++)
    {
        h = 0;

        for (int j = 0; j < M; j++)
        {
            if (h < map[i][j]) h = map[i][j];
        }

        ans += 2 * h;
    }

    //수직
    for (int j = 0; j < M; j++)
    {
        v = 0;
        for (int i = 0; i < N; i++)
        {
            if (v < map[i][j]) v = map[i][j];
        }

        ans += 2 * v;
    }

    cout << ans;
}