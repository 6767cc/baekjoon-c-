// 4963.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int sea[60][60];
int X[] = { 1, -1, 0, 0, 1, 1, -1, -1 };

int Y[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void dfs(int x, int y, int i, int j)
{
    sea[x][y] = 0;

    for (int C = 0; C < 8; C++)
    {
        int xx = x + X[C];
        int yy = y + Y[C];

        if (xx < 0 || yy < 0 || xx > i || yy > j) continue;

        if (sea[xx][yy])
        {
            dfs(xx, yy, i, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    vector<int> ans;

    cin >> i >> j;
    while (i != 0 || j != 0)
    {
        int cot = 0;

        for (int x = 0; x < j; x++)
            for (int y = 0; y < i; y++)
                cin >> sea[x][y];

        for (int x = 0; x < j; x++)
            for (int y = 0; y < i; y++)
            {
                if (sea[x][y])
                {
                    dfs(x, y, i, j);
                    cot++;
                }
            }

        ans.push_back(cot);

        for (int x = 0; x < j; x++)
            for (int y = 0; y < i; y++)
                sea[i][j] = 0;
        cin >> i >> j;
    }

    for (int Ans = 0; Ans < ans.size(); Ans++)
    {
        cout << ans[Ans] << '\n';
    }
}