// 9082.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

string isCount;
char isTrap[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, K, N, cot, m;
    vector<int> ans;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cot = 0;

        cin >> N >> isCount;
        for (int j = 0; j < N; j++)
        {
            cin >> isTrap[j];
        }

        for (int j = 0; j < N; j++)
        {
            m = isCount[j] - '0';
            cot += m;
        }

        a = cot % 3;

        if (a == 0) ans.push_back(cot / 3);
        else ans.push_back(cot / 3 + 1);
    }

    for (auto loop : ans)
        cout << loop << endl;
}