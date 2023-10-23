// 1027.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;
int Building[51];
int IsSee[51];

int N; 
int ans = -1;

//처음보는 곳, 볼수 있는지 체크, 이전 기울기
void SeeCh(int PTS, int PCh, double Inclination)
{
    if (PCh == N + 1) return;
    double NewInclination = (double)(Building[PCh] - Building[PTS]) / (PCh - PTS);
    //현재 기울기가 이전에 가장 높은 기울기보다 크면 보이는 건물
    if (NewInclination > Inclination)
    {
        IsSee[PTS]++;
        IsSee[PCh]++;
        SeeCh(PTS, PCh + 1, NewInclination);
    }
    else SeeCh(PTS, PCh + 1, Inclination);
}
int main()
{
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        int B;
        cin >> B;
        Building[i] = B;
        IsSee[i] = 0;
    }

    for (int i = 1; i <= N;i++)
    {
        SeeCh(i, i+1, -1000000000);
    }

    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, IsSee[i]);
    }
    
    cout << ans;
}
