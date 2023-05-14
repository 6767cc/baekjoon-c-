// 4948.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int N = 1, cot;
    vector<int> ans;

    while (N != 0)
    {
        cin >> N;
        if (N == 0) break;
        cot = 0;

        for (int i = N + 1; i <= 2 * N; i++)
        {
            if (IsPrime(i))
            {
                cot++;
            }
        }
        ans.push_back(cot);
    }

    for (auto loop : ans)
    {
        cout << loop << endl;
    }
}