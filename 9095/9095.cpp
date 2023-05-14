// 9095.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int method[12]; // n만드는 방법
    queue<int> input;

    method[0] = 0;
    method[1] = 1;
    method[2] = 2;
    method[3] = 4;

    for (int i = 4; i < 12; i++)
    {
        method[i] = method[i - 1] + method[i - 2] + method[i - 3];
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        input.push(m);
    }

    for (int i = 0; i < n; i++)
    {
        m = input.front();
        cout << method[m] << "\n";
        input.pop();
    }
}