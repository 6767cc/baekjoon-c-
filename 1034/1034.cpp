// 1034.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

string map[51];
bool Map[51][51];
int M, N, K;

vector<bool[51][51]> MapList;

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        cin >> map[i];

        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '0') Map[i][j] = false;
            else Map[i][j] = true;
        }
    }
    cin >> K;
}