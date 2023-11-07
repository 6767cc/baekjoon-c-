#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<string> Word;
vector<string> AlphabetList;

vector<pair<char, int>> ChAlphabet;
bool AC[26];
bool ishit[10];

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

    for (string alpabetlist : AlphabetList)
    {
        ChAlphabet.clear();
        memset(AC, false, sizeof(AC));

        for (char alpabet : alpabetlist)
        {
            if (!AC[alpabet - 'a'])
            {
                AC[alpabet - 'a'] = true;
                ChAlphabet.push_back(pair<char, int>(alpabet, 0));
            }
        }

        for (string word : Word)
        {
            memset(ishit, false, sizeof(ishit));
            bool Ch1 = true;

            for (char WS : word)
            {
                if (ishit[WS - 'a']) continue;

                bool isNotCreate = false;

                for (pair<char, int> chalphabet : ChAlphabet)
                {
                    if(chalphabet.first == WS)
                    {
                        ishit[WS - 'a'] = true;
                        continue;
                    }

                    isNotCreate = true;
                }

                if (isNotCreate)
                {
                    Ch1 = false;
                    break;
                }
            }

            if (Ch1) 
            {
                for (int i = 0; i < 26; i++)
                {
                    if (AC[i]) 
                    {
                        for (pair<char, int> a : ChAlphabet)
                        {
                            if (a.first - 'a' == i) a.second++;
                        }
                    }
                }
            }
        }

        int Max = -1;
        int Min = 20001;

        for (pair<char, int> a : ChAlphabet)
        {
            if (a.second > Max)
            {
                Max = a.second;
                maxans.clear();
                maxans.push_back(a.first);
            }
            else if(a.second == Max)
            {
                maxans.push_back(a.first);
            }

            if (a.second < Min)
            {
                Min = a.second;
                minans.clear();
                minans.push_back(a.first);
            }
            else if(a.second == Min)
            {
                minans.push_back(a.first);
            }
        }

        sort(maxans.begin(), maxans.end());
        sort(minans.begin(), minans.end());

        for(char minA : minans)
        {
            cout << minA;
        }

        cout << ' ' << Min << ' ';

        for (char MaxA : maxans)
        {
            cout << MaxA;
        }

        cout << ' ' << Max << '\n';
    }
}