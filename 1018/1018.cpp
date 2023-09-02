#include <iostream>
#include <vector>
using namespace std;

string map[51];

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

vector<int> Ans;

int WB_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map[x + i][y + j] != WB[i][j])
                cnt++;
        }
    }
    return cnt;
}

int BW_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map[x + i][y + j] != BW[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int BWA, WBA;

    int Anser = 32;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
            cin >> map[i];

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            WBA = WB_cnt(i, j);
            BWA = BW_cnt(i, j);

            int Min = min(BWA, WBA);
            Ans.push_back(Min);
        }
    }

    for (int ans : Ans)
    {
        if (Anser > ans) Anser = ans;
    }

    cout << Anser;
}