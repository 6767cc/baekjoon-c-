#include <iostream>
#include <vector>
#include<memory.h>

using namespace std;

vector<string> Word;
vector<string> AlphabetList;

vector<pair<char, int>> ChAlphabet;
bool Ch[9];

int main()
{
    string input;
    
    cin >> input;
    while (input == "-")
    {
        Word.push_back(input);
        cin >> input;
    }

    cin >> input;
    while (input == "#")
    {
        AlphabetList.push_back(input);
        cin >> input;
    }

    for (string Alphabetlist : AlphabetList)
    {
        ChAlphabet.clear();

        for (char A : Alphabetlist)
        {
            ChAlphabet.push_back(pair<char, int>(A, 0));
        }

        for (string word : Word)
        {
            for (char alphabet : word)
            {
                int C = 0;
                memset();
                for (int i = 1; i <= 9; i++)
                {
                    if (alphabet == ChAlphabet[i-1].first)
                    {
                        Ch[i] = true;
                        continue;
                    }
                    else C++;
                }

                if (C == 9) break;
            }
        }
    }
}