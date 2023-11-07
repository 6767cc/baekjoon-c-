// 2617.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> NV[100];
vector<int> RV[100];

bool NCh[100], RCh[100];
int HC, LC;

void DFS(int beadNumber)
{
    NCh[beadNumber] = true;

    for (int bead : NV[beadNumber])
    {
        if (!NCh[bead])
        {
            HC++;
            DFS(bead);
        }
    }
}

void RDFS(int beadNumber)
{
    RCh[beadNumber] = true;

    for (int bead : RV[beadNumber])
    {
        if (!RCh[bead])
        {
            LC++;
            RDFS(bead);
        }
    }
}

void reset()
{
    HC = 0; 
    LC = 0;

    for (int i = 1; i <= N; i++)
    {
        NCh[i] = false;
        RCh[i] = false;
    }
}

int main()
{
    cin >> N >> M;
   
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        NV[a].push_back(b);
        RV[b].push_back(a);
    }

    
    for (int i = 1; i <= N; i++)
    {
        reset();

        DFS(i);
        RDFS(i);

        if (HC >= (N + 1) / 2 || LC >= (N + 1) / 2) ans++;
    }

    cout << ans;
}
