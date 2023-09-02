// 1303.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> soldiers;
vector<vector<bool>> visited;
int powerW, powerB;
int ansW, ansB;
int x[] = { -1, 1, 0, 0 };
int y[] = { 0, 0, -1, 1 };

void dfs(int row, int col, char team) {
    visited[row][col] = true;

    if (team == 'W')
        powerW++;
    else
        powerB++;

    for (int i = 0; i < 4; i++) {
        int xx = row + x[i];
        int yy = col + y[i];

        if (xx < 0 || xx >= M || yy < 0 || yy >= N)
            continue;

        if (!visited[xx][yy] && soldiers[xx][yy] == team)
            dfs(xx, yy, team);
    }
}

int main() 
{
    cin >> N >> M;
    soldiers.resize(M, vector<char>(N));
    visited.resize(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) 
            cin >> soldiers[i][j];

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (!visited[i][j]) 
            {
                if (soldiers[i][j] == 'W')
                    dfs(i, j, 'W');
                else
                    dfs(i, j, 'B');
            }
        }
    }

    cout << powerW << ' ' << powerB << endl;

    return 0;
}