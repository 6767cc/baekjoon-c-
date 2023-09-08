// 1389.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

vector<int> map[101];
int N, M;

bool PointPassCheck[101];

int BFS(int StrantNumber)
{
    int a = 0, KBN = 0;

    queue<int> q;
    q.push(StrantNumber);
    PointPassCheck[StrantNumber] = true;

    while (!q.empty())
    {
        a++;

        int pass = q.front();
        q.pop();

        for (int i : map[pass])
        {
            if (!PointPassCheck[i])
            {
                q.push(i);
                PointPassCheck[i] = true;
                KBN += a;
            }
        }
    }

    return KBN;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans;
    int Beforebfs = NULL;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int FriendA, FriendB;
        cin >> FriendA >> FriendB;

        map[FriendA].push_back(FriendB);
        map[FriendB].push_back(FriendA);
    }

    for (int i = 1; i <= N; i++)
    {
        int bfs = BFS(i);
        if (Beforebfs == NULL || Beforebfs >= bfs) ans = i;

        Beforebfs = bfs;
        memset(PointPassCheck, false, sizeof(PointPassCheck));
    }

    cout << ans;
}