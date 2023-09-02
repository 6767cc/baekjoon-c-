#include <iostream>

using namespace std;

int ans[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, add = 0;
    cin >> N;

    //자릿수 체크
    for (int i = 1; N != 0; i *= 10) 
    {
        int POW = N % 10;
        N /= 10;

        //가장 위에 자리는 0이 오면 안됨
        ans[0] -= i;

        //나머지 보다 작은 경우
        for (int j = 0; j < POW; j++) 
            ans[j] += (N + 1) * i;

        //나머지랑 같은 경우
        ans[POW] += N * i + 1 + add;
        add += POW * i;

        //나머지보다 큰 경우
        for (int j = POW + 1; j <= 9; j++) 
            ans[j] += N * i;
    }

    for (int i : ans)
    {
        cout << i << " ";
    }
}