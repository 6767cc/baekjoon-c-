// 1058.1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char map[51][51];
bool Ch[51][51];

int NCount[51];
int ans = 0;

vector<pair<int, int>> Friend_AB;

int main()
{
	cin >> N;

	//입력 및 저장
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'Y' && !Ch[i][j])
			{
				Ch[i][j] = true;
				Ch[j][i] = true;

				Friend_AB.push_back(pair<int, int>(i, j));
			}
		}


	for (pair<int, int> Friend_ab : Friend_AB)
	{
		cout << Friend_ab.first << ' ' << Friend_ab.second << "\n";
	}

	for (pair<int, int> Friend_ab : Friend_AB)
	{
		memset(Ch, false, sizeof(Ch));
		int FriendCount = 0;

		for (pair<int, int> Friend_ac : Friend_AB)
		{
			//앞에가 친구
			if (Friend_ac.first == Friend_ab.first && !Ch[Friend_ab.first][Friend_ab.second])
			{

			}

			if (Friend_ac.second == Friend_ab.first && !Ch[Friend_ab.first][Friend_ab.second])
			{

			}

			//뒤에가 친구 
			if (Friend_ac.second == Friend_ab.second && !Ch[Friend_ab.first][Friend_ab.second])
			{

			}

			if (Friend_ac.first == Friend_ab.second && !Ch[Friend_ab.first][Friend_ab.second])
			{

			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, NCount[i]);
	}

	cout << ans;
}
