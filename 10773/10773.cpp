// 10773.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int K, Z, ans = 0;
    vector<int> vec;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> Z;
        if (Z == 0) vec.pop_back();
        else vec.push_back(Z);
    }

    for (auto loop : vec)
    {
        ans += loop;
    }

    cout << ans << endl;
}