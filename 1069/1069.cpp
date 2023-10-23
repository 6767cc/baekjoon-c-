// 1069.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double X, Y, D, T, ans;

int main()
{
    cin >> X >> Y >> D >> T;
    
    cout << fixed;
    cout.precision(9);

    double distance = sqrt(pow(X, 2) + pow(Y, 2));

    //그냥 걷기
    ans = distance;

    //T가 D보다 크게되면 점프하는 의미가 없음 
    if (D > T) 
    {   
        int jumpCount = distance / D;
        distance = distance - jumpCount * D;

        //걷기, 점프+걷기, 점프 - 3가지 경우

        if (jumpCount == 0)
        {
            ans = min(ans, min(T + D - distance, 2.0 * T));
        }
        else
        {
            ans = min(ans, min(jumpCount * T + distance, (jumpCount + 1.0) * T));
        }
    }

    cout << ans;
}