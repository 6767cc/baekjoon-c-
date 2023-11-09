// 1043.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
int KnowCount;

vector<int> KnowHum;
vector<int> Party[51];
bool SayTrue[51];

int main()
{
    cin >> N >> M;
    
    cin >> KnowCount;

    for (int i = 0; i < KnowCount; i++)
    {
        int KnowHuman;
        cin >> KnowHuman;
        KnowHum.push_back(KnowHuman);
    }

    for (int i = 0; i < M; i++)
    {
        int PartyKnowCount;
        cin >> PartyKnowCount;

        for (int j = 0; j < PartyKnowCount; j++)
        {
            int P;
            cin >> P;
            Party[i].push_back(P);
        }
    }
}