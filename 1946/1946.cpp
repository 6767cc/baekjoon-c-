// 1946.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int i, Ans[20];
int N, DR, IR;

bool crit(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

//2. 숫자 받기 & 받은 숫자를 저장 및 first 순서로 정렬
void recruitment()
{
    vector<pair<int, int>> vec;

    cin >> N;

    for (int j = 0; j < N; j++)
    {
        cin >> DR >> IR;
        vec.push_back(pair<int, int>(DR, IR));
    }

    sort(vec.begin(), vec.end(), crit);

    //3. ans = 0, 으로 저장 후 밑으로 내리면서 숫자가 더 작아지면 ans++, 갱신
    int ans = 0;
    int min = vec[0].second;

    for (int i = 0; i < N; i++)
    {
        if (min >= vec[i].second)
        {
            ans++;
            min = vec[i].second;
        }
    }

    //4. 끝난 후 ans 값을 배열에 저장
    Ans[i] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //1. 반복문
    int a;
    cin >> a;

    for (i = 0; i < a; i++) recruitment();

    //5. 돌린 숫자만큼 출력 
    for (i = 0; i < a; i++) cout << Ans[i] << "\n";
}