// 1038.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<queue>

using namespace std;

int N;
int idx;

queue<long long> q;
long long arr[2000];

int main()
{
    cin >> N;

    if (N < 10) cout << N;
    else if (N > 1022) cout << -1;//힌트 받음 - 최대크기는 9876543210
    else
    {
        //0-9까지는 위에서 이미 처리 함
        for (int i = 0; i < 10; i++)
        {
            q.push(i);
            arr[i] = i;
        }

        idx = 9;

        while (idx <= N)
        {
            if (q.empty()) break;

            long long a = q.front();
            q.pop();
            int POW = a % 10;

            //일의자리 숫자만큼 나아감
            for (int i = 0; i < POW; i++)
            {
                idx++;
                q.push(a * 10 + i);
                arr[idx] = a * 10 + i;
            }
        }

        cout << arr[N];
    }
}