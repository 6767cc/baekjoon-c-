// 1009.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int main()
{
    int T, a, b;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;

        a = a % 10;
        b = b % 4;

        if (a == 1 || a == 5 || a == 6) ans.push_back(a);
        else if (a == 0) ans.push_back(10);
        else if (a == 4 || a == 9)
        {
            if (b % 2 == 1) ans.push_back(a);
            else ans.push_back((a * a) % 10);
        }
        else
        {
            if (b == 1) ans.push_back(a);
            else if (b == 2) ans.push_back((a * a) % 10);
            else if (b == 3) ans.push_back((a * a * a) % 10);
            else if (b == 0) ans.push_back((a * a * a * a) % 10);
        }
    }

    for (int i = 0; i < T; i++) cout << ans[i] << '\n';
}