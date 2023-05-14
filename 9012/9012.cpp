// 9012.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, cot;
    string str;
    stack<char> P;
    vector<string> vec;

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        //초기화
        str.clear();
        while (!P.empty()) P.pop();

        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            // 비어있으면 그냥 추가
            if (P.empty())
            {
                P.push(str[j]);
                continue;
            }

            if (str[j] == ')' && P.top() == '(')
            {
                P.pop();
                continue;
            }
            else P.push(str[j]);

            if (P.top() == ')') break;
        }
        if (!P.empty()) vec.push_back("NO");
        else vec.push_back("YES");
    }

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}