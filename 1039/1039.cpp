// 1039.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string N;
int K;

int S[1000001][11];

int dfs(string A, int cot)
{
    if (cot == K) return stoi(A);

    int& r = S[stoi(A)][cot];
    if (r != -1) return r;

    for(int i = 0; i< A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
        {
            if (i == 0 && A[j] == '0') continue;

            swap(A[i], A[j]);
            r = max(r, dfs(A, cot + 1));
            swap(A[i], A[j]);
        }

    return r;
}

int main()
{
    cin >> N >> K;
    memset(S, -1, sizeof(S));

    if (N.size() == 1) cout << -1;
    else if (N.size() == 2 && (N[0] == '0' || N[1] == '0')) cout << -1;
    else cout << dfs(N, 0);;;
}