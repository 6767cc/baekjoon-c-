// 1068.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, CutNode;

vector<int>Tree[51];
int rootNode;
int ans = 0;

int LeafCh(int L)
{
    if (L == CutNode) return -1;
    if (!Tree[L].size())
    {
        ans++;
        return 0;
    }

    for (int i = 0; i < Tree[L].size(); i++)
    {
        int T = LeafCh(Tree[L][i]);
        if (T == -1 && Tree[L].size() == 1)
            ans++;
    }

    return 0;
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
        else rootNode = i;
    }

    cin >> CutNode;
    LeafCh(rootNode);

    cout << ans;
}