// 1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> Map[10001];

int N, M, StartPoint;

bool PointPassCheck[1001];

vector<int> DFSans;
vector<int> BFSans;

void DFS(int StartPoint)
{
    PointPassCheck[StartPoint] = true;
    DFSans.push_back(StartPoint);

    for (int i : Map[StartPoint])
    {
        if (!PointPassCheck[i]) DFS(i);
    }
}

void BFS(int StartPoint)
{
    queue<int> q;
    q.push(StartPoint);
    PointPassCheck[StartPoint] = true;

    while (!q.empty())
    {
        int pass = q.front();
        q.pop();
        BFSans.push_back(pass);

        for (int i : Map[pass])
        {
            if (!PointPassCheck[i]) 
            {
                q.push(i);
                PointPassCheck[i] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> StartPoint;

    //입력
    for (int i = 0; i < M; i++)
    {
        int PointA, PointB;

        cin >> PointA >> PointB;
        Map[PointA].push_back(PointB);
        Map[PointB].push_back(PointA);
    }

    //작은 순서
    for (int i = 1; i <= N; i++)
    {
        sort(Map[i].begin(), Map[i].end());
    }

    DFS(StartPoint);
    
    memset(PointPassCheck, false, sizeof(PointPassCheck));
    
    BFS(StartPoint);

    for (int i : DFSans)
    {
        cout << i << " ";
    }

    cout << "\n";

    for (int i : BFSans)
    {
        cout << i << " ";
    }
}