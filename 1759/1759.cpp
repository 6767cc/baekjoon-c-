// 1759.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int L, C;
bool Alphabet[26];

vector<char> AlphabetUsed;
vector<string> AnsList;

void ansCreate()
{
    string ans = "";

    for (char isAlphabet : AlphabetUsed)
    {
        ans += isAlphabet;
    }

    AnsList.push_back(ans);
}

//현재 검사하고 있는 알파벳, 자음카운트, 모음 카운트, 총 카운트
void dfs(int idx, int ConsonantCount, int VowelCount, int cot)
{
    if (L == cot && ConsonantCount > 1 && VowelCount > 0) ansCreate();
    else if (L > cot)
    {
        for (int i = idx + 1; i < 26; i++)
        {
            if (Alphabet[i])
            {
                char c = i + 'a';
                AlphabetUsed.push_back(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    dfs(i, ConsonantCount, VowelCount + 1, cot + 1);
                }
                else dfs(i, ConsonantCount + 1, VowelCount, cot + 1);

                AlphabetUsed.pop_back();
            }
        }
    }
}

int main()
{
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        char c;
        cin >> c;
        
        Alphabet[c - 'a'] = true;
    }
    
    dfs(-1, 0, 0, 0);

    for (string ans : AnsList)
    {
        cout << ans << "\n";
    }
}
