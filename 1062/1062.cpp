// 1062.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<string> Word;

bool Alphabet[26];
int ans = 0;

void MaxAnsCh()
{
    int CaseAns = 0;
    //먼저 쓸 단어를 고른 다음 다음 함수 돌리기
    for (int i = 0; i < Word.size(); i++)
    {
        bool Ch = true;

        for (int j = 4; j < Word[i].size() - 4; j++)
        {
            if (!Alphabet[Word[i][j] - 97])
            {
                Ch = false;
                continue;
            }
        }

        if (Ch) CaseAns++;
    }

    ans = max(ans, CaseAns);
}


void dfs(int idx ,int k)
{
    if (K - 5 == k) MaxAnsCh();
    else
    {
        for (int i = idx; i < 26; i++)
        {
            if (Alphabet[i]) continue;
            else
            {
                Alphabet[i] = true;
                dfs(i, k+1);
                Alphabet[i] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        Word.push_back(word);
    }

    //대화를 위한 최소 조건
    Alphabet[0] = true;
    Alphabet[2] = true;
    Alphabet[8] = true;
    Alphabet[13] = true;
    Alphabet[19] = true;

    if (K > 4) dfs(0, 0);

    cout << ans;
}