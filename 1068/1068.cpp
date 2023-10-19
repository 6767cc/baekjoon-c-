// 1068.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, CutNode;

//first가 시작점, seconed가 끝점
vector<int>Tree[51];
vector<int>ChNode;
vector<int> Cutvec;
int ans = 0;

void Clear(int CutNode)
{
    for (int i = 0; i < Tree[CutNode].size(); i++)
    {
        Clear(Tree[CutNode][i]);
    }

    Tree[CutNode].clear();
}

void LeafCh(int L)
{
    if (Tree[L].empty())
    {
        ans++;
        return;
    }

    for (int i = 0; i < Tree[L].size(); i++)
    {
        LeafCh(Tree[L][i]);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int Node;
        cin >> Node;

        //노드 연결
        if (Node != -1)
        {
            Tree[Node].push_back(i);
        }
        else ChNode.push_back(i);
    }

    cin >> CutNode;
    Clear(CutNode);

    for (int chNode : ChNode)
    {
        LeafCh(chNode);
    }

    //자기 자신이 카운트 된 경우를 뺀 것
    cout << ans - 1;
}