// 1100.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

char map[8][8];

int main()
{
    int i, j, ans = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++) scanf("%c", &map[i][j]);
    }

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            if (map[i][j] == 70 && (i + j) % 2 == 1) ans++;
        }
}