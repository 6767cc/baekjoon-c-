// 2805.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int Tn, K;
long long int Start, End, mid, sum, ans = 0;

vector<long int> TreeL; // 나무 길이 저장

//입력 및 정렬
void Input()
{
    int r;
    cin >> Tn >> K;

    //나무들 받기
    for (int i = 0; i < Tn; i++)
    {
        cin >> r;
        TreeL.push_back(r);
    }
}

// 이분탐색 준비
void Set()
{
    sort(TreeL.begin(), TreeL.end());

    Start = 0;
    End = TreeL[Tn - 1]; // 입력조건
}

// 탐색실행
void Sol()
{
    while (Start <= End)
    {
        sum = 0;
        mid = (Start + End) / 2;

        for (int i = 0; i < Tn; i++)
        {
            if (TreeL[i] - mid > 0) sum += TreeL[i] - mid;
        }

        if (sum >= K)
        {
            Start = mid + 1;
            if (mid > ans) ans = mid;
        }
        else End = mid - 1;
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Set();
    Sol();
}