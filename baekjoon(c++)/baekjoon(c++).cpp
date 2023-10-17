#include <iostream>
#include <string>

using namespace std;

string Number;

int N;
bool Pass;

int main()
{
    cin >> N;
    if (N == 0) cout << 0;
    else
    {
        int i = 1;
        int number = 1;

        while (i < N)
        {
            //스트링으로 바꾸고
            Number = to_string(number);
            Pass = true;
            int Ch = 10;

            //그걸 체크한 다음
            for (char num : Number)
            {
                int Num = num - '0';

                if (Num < Ch) Ch = Num;
                else
                {
                    Pass = false;
                    break;
                }
            }

            //체크가 제대로 돌아갔다면 i를 ++
            if (Pass) i++;

            //그 다음 숫자 확인
            number++;
        }

        cout << number;
    }
}
