// 1541.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string input;

string PlusNumber[51];
string MinusNumber[51];

double ans = 0;

int main()
{
    int i = 0, j = -1;
    bool M = false;

    cin >> input;

    for (char c : input)
    {
        if ((c >= '0' && c <= '9') && !M)
        {
            PlusNumber[i] += c;
        }
        else if((c >= '0' && c <= '9') && M)
        {
            MinusNumber[j] += c;
        }
        else if (c == '+' && !M)
        {
            i++;
        }
        else if (c == '+' && M)
        {
            j++;
        }
        else if(c == '-')
        {
            M = true;
            j++;
        }
    }

    for (int k = 0; k <= i; k++)
    {
        double a = stod(PlusNumber[k]);

        ans += a;
    }

    for (int k = 0; k <= j; k++)
    {
        double a = stod(MinusNumber[k]);

        ans -= a;
    }

    cout << ans;
}