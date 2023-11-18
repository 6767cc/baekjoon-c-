// 1082.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int P[11];
vector<pair<int, int>> p;
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        p.push_back(pair<int, int>(P[i], i));
    }

    sort(p.begin(), p.end());
    cin >> M;


    //숫자가 0 단 하나
    if (N == 1)
    {
        cout << "0";
        return 0;
    }

    //가장 가격이 싼 숫자가 0일 경우
    if (p[0].second == 0)
    {
        int m = M - p[1].first;
        if (m < 0)
        {
            cout << "0";
            return 0;
        }

        ans += to_string(p[1].second);
        M -= p[1].first;

        int cot = M / p[0].first;
        for (int i = 0; i < cot; i++)
        {
            ans += to_string(p[0].second);
            M = M - p[0].first;
        }
    }
    //가격이 가장 싼 숫자가 0이 아닐경우
    else
    {
        int cot = M / p[0].first;
        for (int i = 0; i < cot; i++)
        {
            ans += to_string(p[0].second);
            M -= p[0].first;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        bool Ch = false;

        int Changer = P[ans[i] - '0'];

        for (int j = N - 1; j >= 0; j--)
        {
            //남은 돈으로 바꿀 수 있는 숫자면 바꾸기
            if (M - (P[j] - Changer) >= 0)
            {
                    M -= P[j] - Changer;
                    Ch = true;
                    ans[i] = j + '0';
            }
            if (Ch) break;
        }
        if (!Ch) break;
    }

    cout << ans;
}