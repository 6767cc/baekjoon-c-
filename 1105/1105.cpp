// 1105.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L, R, ans = 0;

    cin >> L >> R;

    string l, r;

    l = to_string(L);
    r = to_string(R);
    //자릿수 같을 경우만 아니면 0
    if (l.length() == r.length())
    {
        for (int i = 0; i < l.length(); i++)
        {
            if (l[i] != r[i]) break;

            if (l[i] == '8' && r[i] == '8') ans++;
        }
    }
    cout << ans;
}