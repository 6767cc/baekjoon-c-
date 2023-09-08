// 1389.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int map[101][101];
int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int FriendA, FriendB;
        cin >> FriendA >> FriendB;

        map[FriendA][FriendB] = 1;
        map[FriendB][FriendA] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) 
        {
            if (i != j && map[i][j] != 1)
            {
                map[i][j] = 0xfffffff;
            }
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            for (int k = 1; k <= N; k++) 
            {
                if (map[j][i] + map[i][k] < map[j][k]) 
                {
                    map[j][k] = map[j][i] + map[i][k];
                }

            }
        }
    }
    
    int V = 0xfffffff;
    int ans;

    for (int i = 1; i <= N; i++) 
    {
        int tmp = 0;
        for (int j = 1; j <= N; j++) 
        {
            tmp += map[i][j];
        }
        if (tmp < V) 
        {
            V = tmp;
            ans = i;
        }
    }

    cout << ans;
}