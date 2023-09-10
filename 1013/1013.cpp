// 1013.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <regex>
#include <vector>

using namespace std;
vector<string> Ans;

int test;     
string str;

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);


    cin >> test;

    for (int t = 0;t < test;t++) 
    {
        cin >> str;
        if (regex_match(str, regex("(100+1+|01)+"))) Ans.push_back("YES");
        else Ans.push_back("NO");
    }

    for (string ans : Ans)
    {
        cout << ans << "\n";
    }
}
