// 2293.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int ans;

void input(int n, int k, vector<int> coin)
{
    int a;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        coin.push_back(a);
    }
}

void sol(int n, int k, int ch[101], vector<int> coin)
{
    if (k == 0)
    {
        ans++;
        return;
    }

    for (int i = 0; i < coin.size(); i++)
    {
        k += coin[i];
        ch[i]++;
        sol(n, k, ch, coin);
    }
}

int main()
{
    int n, k, ans = 0;
    int ch[101] = { 0, };
    vector <int> coin;

    input(n, k, coin);
    sol(n, k, ch, coin);

    cout << ans << endl;
}