// 1017.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int PrimeNumber[2000];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        v.push_back(M);
    }

    for (int i = 2; i <= sqrt(2000); i++)
    {
        if (PrimeNumber[i]) continue;

        for (int j = i * i; j < 2000; j + i)
        {
            PrimeNumber[j] = 0;
        }
    }

    for (int i = 1; i < N; i++)
    {
        int ChNumber = v[0] + v[i];

        if (PrimeNumber[ChNumber] != 0)
        {
            for (int j = 1; j < N; j++)
            {
                if (j == i) continue;
            }
        }
    }
}