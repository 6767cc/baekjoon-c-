// 1158.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    int N, K, i, n, r = 1;

    cin >> N >> K;
    for (i = 1; i <= N; i++) q.push(i);

    cout << "<";
    while (1)
    {
        if (q.size() == 1) break;

        if (r % K == 0) {
            n = q.front();
            cout << n << ", ";
            q.pop();
        }
        else
        {
            n = q.front();
            q.push(n);
            q.pop();
        }
        r++;
    }
    n = q.front();

    cout << n << ">";
}