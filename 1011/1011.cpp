// 1011.cpp : 이 파일에는 'main' 함수가 포함됩니다.거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int K;
    vector<int> AnsList;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        long long N, M, distance;
        bool pass = false;
        long long passcount = 0;
        long long ans = 0;

        cin >> N >> M;
        distance = M - N;

        while (!pass)
        {
            if (passcount * passcount >= distance)
            {
                if ((passcount - 1) * (passcount - 1) + (passcount - 1) < distance)
                {
                    AnsList.push_back((passcount - 1) * 2 + 1);
                }
                else
                {
                    AnsList.push_back((passcount - 1) * 2);
                }
                pass = true;
            }
            passcount++;
        }
    }

    for (int Ans : AnsList)
    {
        cout << Ans << "\n";
    }
}