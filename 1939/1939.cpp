// 1939.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>

using namespace std;
vector<pair<int , int>> map[10001];

int N, M;
int Start, Goal;

int main()
{
    cin >> N >> M;

    //map[A] ={pair<int, int>(B, C)} 라면 A에서 B로 가는 다리는 거리가 C 
    for (int i = 0; i < N; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        map[A].push_back(pair<int, int>(B, C));
        map[B].push_back(pair<int, int>(A, C));
    }
    cin >> Start >> Goal;


}