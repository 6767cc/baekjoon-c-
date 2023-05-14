// 2166.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void input(int N, vector<pair<int, int>> point)
{
    int x, y;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        point.push_back({ x, y });
    }

}

double OuterProduct(double x1, double x2, double x3, double y1, double y2, double y3)
{
    double a = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

    return a;
}

void sol(int N, vector<pair<int, int>> point)
{
    double ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans = ans + OuterProduct(point[0].first, point[i - 1].first, point[i].first, point[0].second, point[i - 1].second, point[i].second);
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(ans) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int, int>> Point;

    cin >> n;

    input(n, Point);
    sol(n, Point);
}