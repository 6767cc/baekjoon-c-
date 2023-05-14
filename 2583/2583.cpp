// 2583.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int m, n, k, a, b, c, d;
int ans = 0; //영역 갯수
bool arr[101][101]; //전체영역
vector<int> S; //영역 넓이

void bfs(int v, int h)
{
    queue<pair<int, int>> q;
    q.push(make_pair(v, h));
    arr[v][h] = 1;
    int cnt = 1;
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4;i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (yy < n && yy >= 0 && xx < m && xx >= 0)
            {
                if (arr[xx][yy] == 0)
                {
                    q.push(make_pair(xx, yy));
                    arr[xx][yy] = 1;
                    cnt++;
                }
            }
        }
    }
    S.push_back(cnt);
}

int main()
{
    cin >> m >> n >> k;

    //영역 분리
    for (int i = 0; i < k;i++)
    {
        cin >> a >> b >> c >> d;

        for (int u = b; u < d; u++)
        {
            for (int w = a; w < c;w++) arr[u][w] = 1;
        }
    }

    //영역 구하기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n;j++)
        {
            if (arr[i][j] == 0)
            {
                bfs(i, j);
                ans++;
            }
        }
    }

    //영역 갯수
    cout << ans << '\n';

    //영역 넓이
    sort(S.begin(), S.end());
    for (int i = 0; i < S.size(); i++) cout << S[i] << " ";

    return 0;
}