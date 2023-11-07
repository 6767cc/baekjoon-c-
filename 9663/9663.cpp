// 9663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
using namespace std;

int N, ans; 
int QP[15];

bool Ch(int QC)
{
    for (int i = 0; i < QC; i++)
    {
        if ((QP[QC] == QP[i]) || (QC - i == abs(QP[QC] - QP[i])))
        {
            return false;
        }
    }
    return true;
}

//각 줄에 넣을 수 있는 퀸은 단 하나
void DFS(int cot)
{
    if (cot == N)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        QP[cot] = i;

        //현재까지 놓은 위치에 새롭게 퀸이 넣을 수 있으면 넣은 상태로 다음거 체크 
        if (Ch(cot))
        {
            DFS(cot + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 1) cout << 1;
    else if(N == 2 || N == 3) cout << 0;
    else
    {
        DFS(0);
        cout << ans;
    }
}