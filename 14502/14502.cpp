#include <iostream>
#include <vector>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int area[8][8];
int testarea[8][8];
int N, M;
vector<pair<int, int>> EmptySpaceList;

int ans = 0;

void dfs(int x, int y)
{
    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && testarea[nx][ny] == 0)
        {
            testarea[nx][ny] = 2;
            dfs(nx, ny);
        }
    }
}

void ansCh()
{
    int TCA = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (testarea[i][j] == 0) TCA++;
        }
    }

    ans = max(ans, TCA);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> area[i][j];
            testarea[i][j] = area[i][j];

            if (area[i][j] == 0)
            {
                EmptySpaceList.push_back(make_pair(i, j));
            }
        }
    }

    //1.벽세우기
    for(int a = 0; a < EmptySpaceList.size(); a++)
        for (int b = a + 1; b < EmptySpaceList.size(); b++)
            for (int c = b + 1; c < EmptySpaceList.size(); c++)
            {
                testarea[EmptySpaceList[a].first][EmptySpaceList[a].second] = 1;
                testarea[EmptySpaceList[b].first][EmptySpaceList[b].second] = 1;
                testarea[EmptySpaceList[c].first][EmptySpaceList[c].second] = 1;

                //2. 바이러스 전파
                for (int x = 0; x < N; x++)
                    for (int y = 0; y < M; y++)
                    {
                        if (testarea[x][y] == 2)
                        {
                            dfs(x, y);
                        }
                    }

                //3. 갯수세서 큰값저장
                ansCh();

                //초기화
                for (int x = 0; x < N; x++)
                    for (int y = 0; y < M; y++)
                        testarea[x][y] = area[x][y];
            }
    cout << ans;
}
