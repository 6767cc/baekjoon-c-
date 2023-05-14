// 1283.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool Ch[26];

class OPTION
{
private:
    string Name; //옵션
    vector<string> Word; // 띄어쓰기를 기준으로하는 단어
    char Shortcut = '1'; //대표하는 영어

public:
    //필드 갱신
    void ChangeName(string a)
    {
        Name = a;
    }

    void AddWord(string a)
    {
        Word.push_back(a);
    }

    void AddShortcut(char a)
    {
        Shortcut = a;
    }

    //필드 출력
    string GetName()
    {
        return Name;
    }

    vector<string> GetWordVector()
    {
        return Word;
    }

    string GetWord(int j)
    {
        return Word[j];
    }

    char GetShortcut()
    {
        return Shortcut;
    }
};

//----------------------------------------------

//입력 받기
void Input(vector<string>& Vector)
{
    int N;
    string s;

    cin >> N;

    cin.ignore(); // cin은 '\n'을 버퍼에 저장한다

    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        s = s;
        Vector.push_back(s);
    }
}

//옵션 이름 저장
void ObjectName(vector<string> input, vector<OPTION>& Object)
{
    for (int i = 0; i < input.size(); i++)
    {
        OPTION c;
        c.ChangeName(input[i] + "0");

        Object.push_back(c);
    }
}

// 옵션의 단어 저장
void ObjectWord(vector<string> List, vector<OPTION>& Object)
{
    for (int i = 0; i < List.size(); i++)
    {
        string S;
        string name = List[i];
        stringstream stream(name);

        while (stream >> S)
        {
            Object[i].AddWord(S);
        }
    }
}

// 옵션 단축키 저장
void ObjectShortcut(vector<string> List, vector<OPTION>& Object)
{
    //4)정해진 규칙으로 받은 옵션 수 만큼 반복
    for (int i = 0; i < List.size(); i++)
    {
        //1) 단어의 문자의 첫 문자가가 객체의 대표 알파벳이 될 경우
        for (int j = 0; j < Object[i].GetWordVector().size(); j++)
        {
            int Ascii = Object[i].GetWord(j)[0];

            if (Ascii >= 65 && Ascii <= 90)
            {
                if (!Ch[Ascii - 'A'])
                {
                    Ch[Ascii - 'A'] = true;
                    Object[i].AddShortcut(Object[i].GetWord(j)[0]);
                    break;
                }
                else continue;
            }
            else if (Ascii >= 97 && Ascii <= 122)
            {
                if (!Ch[Ascii - 'a'])
                {
                    Ch[Ascii - 'a'] = true;
                    Object[i].AddShortcut(Object[i].GetWord(j)[0]);
                    break;
                }
                else continue;
            }
        }

        //2) 줄바꿈 나오기전까지 순서대로 알파벳이 사용되었는지 확인하고 사용되지 않은 알파벳이 있다면 저장
        if (Object[i].GetShortcut() == '1')
        {
            int j = 0;

            while (Object[i].GetName()[j] != '0')
            {
                int Ascii = List[i][j];

                if (Ascii >= 65 && Ascii <= 90)
                {
                    if (!Ch[Ascii - 'A'])
                    {
                        Ch[Ascii - 'A'] = true;
                        Object[i].AddShortcut(List[i][j]);
                        break;
                    }
                }
                else if (Ascii >= 97 && Ascii <= 122)
                {
                    if (!Ch[Ascii - 'a'])
                    {
                        Ch[Ascii - 'a'] = true;
                        Object[i].AddShortcut(List[i][j]);
                        break;
                    }
                }
                //다음 것 확인
                j++;
            }
        }
    }
}

void Print(vector<string> List, vector<OPTION>& Object, vector<string>& Answer)
{
    for (int i = 0; i < List.size(); i++)
    {
        string ans = List[i];

        if (Object[i].GetShortcut() != '1')
        {
            int j = 0;

            while (Object[i].GetName()[j] != '0')
            {
                if (List[i][j] == Object[i].GetShortcut())
                {
                    if (j == 0)
                    {
                        ans.insert(j, "[");
                        ans.insert(j + 2, "]");
                        break;
                    }
                    else
                    {
                        if (List[i][j - 1] == ' ')
                        {
                            ans.insert(j, "[");
                            ans.insert(j + 2, "]");
                            break;
                        }
                    }
                }
                j++;
            }
        }
        if (List[i] != ans)
            Answer.push_back(ans);
        else
        {
            int j = 0;

            while (Object[i].GetName()[j] != '0')
            {
                if (List[i][j] == Object[i].GetShortcut())
                {
                    ans.insert(j, "[");
                    ans.insert(j + 2, "]");

                    break;
                }
                j++;
            }
            Answer.push_back(ans);
        }
    }
}

//입력을 객체의 Name으로 저장
void Object(vector<string> List, vector<OPTION>& Object, vector<string>& Answer)
{
    //이름을 기준으로 객체 만들기
    ObjectName(List, Object);

    //input에서 뛰어쓰기를 기준으로 단어 나눠 객체에 저장
    ObjectWord(List, Object);

    ObjectShortcut(List, Object);

    Print(List, Object, Answer);
}
//------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> input; //입력 저장
    vector<OPTION> object; // 객체 저장
    vector<string> Answer; // 정답 저장

    //입력받아 벡터로 저장
    Input(input);

    //저장받은 벡터를 이용해서 객체 벡터 만들기
    Object(input, object, Answer);

    for (int i = 0; i < Answer.size(); i++)
        cout << Answer[i] << '\n';
}