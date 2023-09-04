// 1240.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, M;
//벡터의 배열은 처음위치 pair의 first는 도착위치, second는 사이거리
vector<pair<int, int>> map[1001];
bool PointPassCheck[1001];
vector<int> ans;

void DFS(int StartPoint, int EndPoint, int distance)
{
    PointPassCheck[StartPoint] = true;

    if (StartPoint == EndPoint)
    {
        ans.push_back(distance);
        return;
    }

    for (pair<int, int> GoPointData : map[StartPoint])
    {
        int Distance = distance + GoPointData.second;
        int NextNode = GoPointData.first;
        if (PointPassCheck[NextNode]) continue;
        PointPassCheck[NextNode] = true;
        DFS(GoPointData.first, EndPoint, Distance);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++)
    {
        int pointA, pointB, distance;
        cin >> pointA >> pointB >> distance;
        map[pointA].push_back({ pointB, distance });
        map[pointB].push_back({ pointA, distance });
    }

    for (int i = 0; i < M; i++)
    {
        int pointA, pointB;
        cin >> pointA >> pointB;

        DFS(pointA, pointB, 0);
        memset(PointPassCheck, false, sizeof(PointPassCheck));
    }

    for (int Ans : ans)
    {
        cout << Ans << "\n";
    }
}