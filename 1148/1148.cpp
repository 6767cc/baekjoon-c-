#include <iostream>
#include <vector>

using namespace std;

vector<string> Word;
vector<string> Alphabet;

int CheckCount[9];

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
        Alphabet.push_back(input);
        cin >> input;
    }

    for (string CheckAlpabetList : Alphabet)
    {
        for (string word : Word)
        {
            for (char wordAlphabet : word)
            {
                for (char CheckAlpabet : CheckAlpabetList)
                {
                    if (CheckAlpabet == wordAlphabet)
                    {

                    }
                }
            }
        }
    }
}