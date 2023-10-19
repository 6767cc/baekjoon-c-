#include <iostream>
#include <vector>
#include<memory.h>

using namespace std;

vector<string> Word;
vector<string> AlphabetList;

vector<pair<char, int>> ChAlphabet;
bool Ch[10];

vector<char> minans;
vector<char> maxans;

int main()
{
    string input;
    
    cin >> input;
    while (input != "-")
    {
        Word.push_back(input);
        cin >> input;
    }

    cin >> input;
    while (input != "#")
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
            bool CreateFailed = false;

            for (char alphabet : word)
            {
                int C = 0;
                memset(Ch, false, sizeof(Ch));

                for (int i = 1; i <= 9; i++)
                {
                    if (alphabet == ChAlphabet[i-1].first)
                    {
                        Ch[i] = true;
                        continue;
                    }
                    else C++;
                }

                if (C == 9)
                {
                    CreateFailed = true;
                    break;
                }
            }

            if (!CreateFailed)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (Ch[i + 1]) ChAlphabet[i].second++;
                }
            }
        }

        //정리된 것들중 가장 큰 것과 가장 작은 것 
        int min = 200001;
        int max = -1;
        minans.clear();
        maxans.clear();

        for (pair<char, int> a : ChAlphabet)
        {
            if (min > a.second) min = a.second;
            if (max < a.second) max = a.second;
        }

        for (pair<char, int> a : ChAlphabet)
        {
            if (a.second == min) minans.push_back(a.first);
            if (a.second == max) maxans.push_back(a.first);
        }

        for (char m : minans)
        {
            cout << m;
        }

        cout << " " << min << " ";

        for (char m : maxans)
        {
            cout << m;
        }

        cout << " " << min << "\n";
    }
}