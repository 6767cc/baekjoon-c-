// 1024.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

long long int N, L;

int main()
{
    cin >> N >> L;
    
    long long int StratPoint = -1;
    long long int EndPoint = -1;

    for (int i = L; i <= 100; i++)
    {
        //배열길이가 짝수일때
        if (i % 2 == 0)
        {
           //중간값 가우스가 있으면
            if (N % i == i / 2)
            {
                StratPoint = N / i - i / 2 + 1;
                EndPoint = N / i + i / 2;
                break;
            }

        }
        //배열길이가 홀수일때
        else
        {
            //중간 하나 빼고 +-로 전부 사라짐
            if (N % i == 0)
            {
                StratPoint = N / i - i / 2;
                EndPoint = N / i + i / 2;
                break;
            }
        }
    }

    if (StratPoint > -1)
    {
        for (long long int i = StratPoint; i <= EndPoint;i++)
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << -1;
    }
}