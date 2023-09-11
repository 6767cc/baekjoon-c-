// 9996.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int test;
string Ch_regex;

string str;
vector<string> Ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> test;
    cin >> Ch_regex;

    for (int i = 0; i < test; i++)
    {
        string A = "", B = "";
        bool StarPass = false;

        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] != '*')
            {
                if (!StarPass) A += str[j];
                else B += str[j];
            }
            else
            {
                StarPass = true;
                continue;
            }
        }
        if (regex_match(str, regex("^[" + A + "][" + B + "]$"))) Ans.push_back("DA");
        else Ans.push_back("NE");
    }

    for (string ans : Ans)
    {
        cout << ans << "\n";
    }
}