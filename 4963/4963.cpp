// 4963.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int X[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int Y[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void reset() 
{
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void DFS(int x, int y) 
{
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) 
    {
        int nx = x + X[i];
        int ny = y + Y[i];

        if (ny < 0 || nx < 0 || nx >= h || ny >= w) continue;

        if (map[nx][ny] == 1 && visited[nx][ny] == 0) 
        {
            DFS(nx, ny);
        }
    }
}

int main()
{
    vector<int> ans;

    while (true)
    {
        reset();

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        int cnt = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == 1 && visited[i][j] == 0)
                {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }

    for (int i : ans)
    {
        cout << i << "\n";
    }
}