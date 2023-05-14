// 11053.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, An, max = 0, cot = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> An;
        if (max < An)
        {
            cot++;
            max = An;
        }
    }

    cout << cot;
}