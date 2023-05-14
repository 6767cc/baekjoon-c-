// 1756.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

//클래스 오븐
class Oven
{
public:
    int Depth; // 오븐 위치 
    int Diameters; // 오븐 지름
    int Put_Ok_Dough; // 오븐에 넣을 수 있는 도우 크기
    bool Is_Dough;

    Oven()
    {
        Diameters = 0;
        Depth = 0;
        Put_Ok_Dough = 0;
        Is_Dough = false;
    }

    void make_Oven(int a, int b)
    {
        Diameters = a;
        Depth = b;
    }
};

//-----------------------------
Oven full_Oven[300003]; // 오븐 정보
int Pizza_Dough[300003]; // 주어지는 반죽 정보 

void input(int& D, int& K)
{
    int diameters, pizza_dough; //2번줄

    cin >> D >> K;

    for (int i = 1; i <= D; i++)
    {
        cin >> diameters;
        full_Oven[i].make_Oven(diameters, i);
    }

    for (int i = 1; i <= K; i++)
    {
        cin >> pizza_dough;
        Pizza_Dough[i] = pizza_dough;
    }
}


int sol(int D, int K)
{
    int D1 = D;

    //넣기 기능한 도우 체크
    for (int i = 1; i <= D; i++)
    {
        if (i == 1)
        {
            full_Oven[i].Put_Ok_Dough = full_Oven[i].Diameters;
            continue;
        }

        full_Oven[i].Put_Ok_Dough = full_Oven[i - 1].Put_Ok_Dough <= full_Oven[i].Diameters ? full_Oven[i - 1].Put_Ok_Dough : full_Oven[i].Diameters;
    }

    int i = 0;
    for (i = 1; i <= K; i++)
    {
        while (full_Oven[D1].Put_Ok_Dough < Pizza_Dough[i])
        {
            if (D1 < 0) break;

            D1--;
        }

        if (i < K) D1--;
        else continue;
    }
    if (D1 < 0) return 0;
    return D1;
}

//-----------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int D, K;

    //정보 받기
    input(D, K);
    int ans = sol(D, K);

    cout << full_Oven[ans].Depth;
}