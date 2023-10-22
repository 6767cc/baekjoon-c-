// 1629.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    std::cout.precision(10);
    std::cout << a / b;
    return 0;
}

// 2 4 8 16 32 64
// 2 1 2 1  2  1
// 2 0 2 0 2 0 2 0
// 2 4 3 1 2 4 3 1 
