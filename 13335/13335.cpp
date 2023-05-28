// 1283.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <queue>

using namespace std;

void Input(int &n, int &w, int &L, queue<int> &truckWeights)
{
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        truckWeights.push(weight);
    }
}

void Sol(int n, int w, int L, queue<int> truckWeights)
{
    queue<pair<int, int>> bridgeWeight;
    int time = 0;
    int totalWeight = 0;

    //트럭이 전부 나가면 멈춤
    while (!truckWeights.empty() || !bridgeWeight.empty())
    {
        time++;

        //다리에 있는 트럭
        if (!bridgeWeight.empty())
        {
            if (time - bridgeWeight.front().second >= w)
            {
                totalWeight -= bridgeWeight.front().first;
                bridgeWeight.pop();
            }
        }

        //아직 출발 못한 트럭
        if (!truckWeights.empty())
        {
            if (totalWeight + truckWeights.front() <= L)
            {
                totalWeight += truckWeights.front();
                bridgeWeight.push(make_pair(truckWeights.front(), time));
                truckWeights.pop();
            }
        }
    }

    cout << time;
}

int main() {
    int n, w, L;
    queue<int> truckWeights;
  
    Input(n, w, L, truckWeights);
    Sol(n, w, L, truckWeights);
}