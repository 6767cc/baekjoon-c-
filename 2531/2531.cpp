// 2531.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int N, d, k, c; // 입력
bool sushiC[30000]; // 체크배열
vector<int> reset; // 저장 후 초기화시 사용

vector<int> sushi; // 숫자 받기

void input()
{
    cin >> N >> d >> k >> c;

    int Sushi;

    for (int i = 0; i < N; i++)
    {
        cin >> Sushi;
        sushi.push_back(Sushi);
    }

    for (int i = 0; i < k; i++)
    {
        sushi.push_back(sushi[i]);
    }
}

void sol()
{
    int NOT, max = 0; // 초밥 가짓수, 최댓값
    for (int i = 0; i < N; i++)
    {
        NOT = 0;

        for (int j = 0; j < k; j++)
        {
            if (!sushiC[sushi[i + j]])
            {
                NOT++;
                sushiC[sushi[i + j]] = !sushiC[sushi[i + j]];
                reset.push_back(sushi[i + j]);
            }
            else continue;
        }
        if (!sushiC[c]) NOT++; // 쿠폰 사용

        if (NOT > max) max = NOT; // 최댓값 갱신

        for (int i = reset.size() - 1; i > -1; i--)
        {
            sushiC[reset[i]] = !sushiC[reset[i]];
            reset.pop_back();
        }
    }

    cout << max << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    sol();
}