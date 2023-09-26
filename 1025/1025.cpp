// 1025.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M;
int Map[10][10];
int ans = -1;

bool Chsqrt(int n)
{
    int SqrtN = sqrt(n);
    if (SqrtN * SqrtN == n) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
            Map[i][j] = str[j] - '0';
    }

    //앞 2개는 모든 칸 - 뒤에 2개는 등차수열(dx, dy는 공차)
    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for(int dx = -N; dx < N; dx++)
                for (int dy = -M; dy < M; dy++)
                {
                    if (dx == 0 && dy == 0) continue;

                    //고를 숫자
                    int x = i;
                    int y = j;

                    //만들어지는 수
                    int num = 0;

                    //x,y가 범위 내에 있을때 까지
                    while (x >= 0 && x < N && y >= 0 && y < M)
                    {
                        num = num * 10 + Map[x][y];

                        if (Chsqrt(num)) 
                        {
                            ans = max(ans, num);
                        }

                        x += dx;
                        y += dy;
                     }
                }

    cout << ans;
}