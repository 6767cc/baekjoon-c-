// 1781.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, DL, CapC, ans; //n,m은 첫째줄 r은 둘째줄
vector<pair<int, int>> vec;

bool crit(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

void set()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> DL >> CapC;
        vec.push_back(pair<int, int>(DL, CapC));
    }

    //vec.second에 따라 내림차순 정리
    sort(vec.begin(), vec.end(), crit);
}

void sol()
{
    //while로 vec가 텅 빌때까지 
    while (!vec.empty())
    {
        ans += vec.end()->second;
        vec.pop_back();

        for (int i = 0; i < vec.size(); i++)
            vec[i].first--;

        //second 전부 1 감소
        while (!vec.empty())
        {
            if (vec.begin()->first > 0) break;
            else vec.erase(vec.begin());
        }
    }

    //정답 출력
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set();
    sol();
}