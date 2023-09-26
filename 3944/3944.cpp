// 3944.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int Test, B;
string D;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Test;

    for (int i = 0; i < Test; i++)
    {
        int ans = 0;
        cin >> B >> D;

        for (char c : D)
        {
            int C = c - '0';
            ans += C;
        }

        ans = ans % (B - 1);
        cout << ans << '\n';
    }
}