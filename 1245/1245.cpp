// 1245.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Map;
vector<vector<bool>> Ch;
int N, M;
int ans;
int x[] = { -1, 1, 0, 0 };
int y[] = { 0, 0, -1, 1 };

void DFS(int x, int y, int Mh)
{

}

int main()
{
    cin >> M, N;

    for(int i = 0; i< N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> Map[i][j];
        }

    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (!Ch[i][j])
            {
                if (Map[i][j] != 0)
                {
                    DFS(i, j, Map[i][j]);
                }
            }
        }

    cout << ans;
}