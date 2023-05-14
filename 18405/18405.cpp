// 18405.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };

//시험관 클래스
class TASTTUBE
{
public:
    int Virus; //바이러스는 번호
    int self_x;//x 좌표
    int self_y;//y 좌표

    TASTTUBE()
    {
        self_x = 0;
        self_y = 0;
        Virus = 0;
    }

    TASTTUBE(int x, int y, int virus_number)
    {
        self_x = x;
        self_y = y;
        Virus = virus_number;
    }

    void AllChange(int x, int y, int virus_number)
    {
        self_x = x;
        self_y = y;
        Virus = virus_number;
    }
    //증식
    void proliferate(int Virus_proliferate)
    {
        if (Virus == 0) Virus = Virus_proliferate;
    }
};

//----------------------------------

TASTTUBE Tasttube_Arr[200][200]; // 배열

//바이러스 번호에 따라 정렬
bool proliferative_order(TASTTUBE a, TASTTUBE b)
{
    return a.Virus < b.Virus;
}

//시험관 정보 받기
void input(vector<TASTTUBE>& TastTube, int& N, int& K)
{
    int is_Virus_Number; // 바이러스 번호
    int is_Breeding_Priority; //증식 우선순위

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> is_Virus_Number;

            Tasttube_Arr[i][j].AllChange(i, j, is_Virus_Number);

            if (is_Virus_Number > 0)
            {
                TastTube.push_back(TASTTUBE(i, j, is_Virus_Number));
            }
        }
}

void TimePasses(vector<TASTTUBE>& TastTube, int N, int K)
{

    int time;
    cin >> time;

    for (int r = 0; r < time; r++)
    {
        //바이러스 번호 따라 정렬
        sort(TastTube.begin(), TastTube.end(), proliferative_order);

        //증식
        for (int i = 0; i < TastTube.size(); i++)
        {
            int VN = TastTube[i].Virus;

            for (int j = 0; j < 4; j++)
            {
                int xx = TastTube[i].self_x + X[j];
                int yy = TastTube[i].self_y + Y[j];

                if (xx < 0 || yy < 0 || xx > N || yy > N) continue;

                Tasttube_Arr[xx][yy].proliferate(VN);
            }
        }

        TastTube.clear();

        //위치값 재저장
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (Tasttube_Arr[i][j].Virus > 0)
                    TastTube.push_back(Tasttube_Arr[i][j]);
            }
    }
}

void Answer(vector<TASTTUBE> TastTube)
{
    int ans_x, ans_y;
    cin >> ans_x >> ans_y;

    cout << Tasttube_Arr[ans_x - 1][ans_y - 1].Virus;
}

auto main() -> int
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("입력.txt", "r", stdin);

    vector<TASTTUBE> tasttube;
    int N, K;

    input(tasttube, N, K);
    TimePasses(tasttube, N, K);
    Answer(tasttube);
}