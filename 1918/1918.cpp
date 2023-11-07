// 1918.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Priority(char C)
{
    if (C == '+' || C == '-') return 1;
    if (C == '*' || C == '/') return 2;

    return 0;
}

int main()
{
    string expression;

    stack<char> Pass;
    
    char c;
    string ans;

    cin >> expression;

    for(int i = 0; i < expression.size(); i++)
    {
        //만나는 경우 4가지
        c = expression[i];

        //1. 알파벳
        if (c >= 'A' && c <= 'Z')
        {
            ans += c;
            continue;
        }
        
        //2. 괄호 - 반대 괄호 만날때까지 기다렸다가 나오면 이전까지 저장된 기호 넣기
        if (Pass.empty() || c == '(')
        {
            Pass.push(c);
            continue;
        }

        if (c == ')')
        {
            while (Pass.top() != '(')
            {
                ans += Pass.top();
                Pass.pop();
            }
            Pass.pop();
            continue;
        }

        //3. 더하기, 빼기 곱하기, 나누기 - 곱하기, 나누기는 더하기 빼기보다 우선
        if (Priority(c) > Priority(Pass.top()))
        {
            Pass.push(c);
        }
        //만약 곱하기가 더하기보다 나중에 들어가려고 하면
        else 
        {
            while (!Pass.empty() && Priority(c) <= Priority(Pass.top()))
            {
                ans += Pass.top();
                Pass.pop();
            }
            Pass.push(c);
        }
    }

    while (!Pass.empty()) 
    {
        ans += Pass.top();
        Pass.pop();
    }

    cout << ans;
}
