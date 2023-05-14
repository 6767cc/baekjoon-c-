// 1929.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a, b, m, n, r;

    cin >> a >> b;

    for (; a <= b; a++)
    {
        for (r = 2; r <= b / 2; r++)
        {
            if (a % r == 0)
                break;
        }

        if (r == b / 2)
        {
            cout << a;
        }
    }
}