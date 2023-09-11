// 11720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

string List;

int main()
{
    int N, ans = 0;

    cin >> N;
    cin >> List;

    for (char i : List)
    {
        int I = i - '0';

        ans += I;
    }

    cout << ans;
}

