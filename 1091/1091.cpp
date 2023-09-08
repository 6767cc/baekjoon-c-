// 1091.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int PlayerGetNumber[48];
int Shuffle[48];
int ansList[48];
bool hit;

int JustBeforeTheShuffleCardList[48];
int ShuffleCardList[48];

int main()
{
	int N, ans = 0;
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> PlayerGetNumber[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> Shuffle[i];
	}

	while (true)
	{
		//셔플 직전을 먼저 저장
		for (int i = 0; i < N; i++)
		{
			JustBeforeTheShuffleCardList[i] = ShuffleCardList[i];
		}

		//전부 같게 들어가면 히트로 바꾸면서 나가기 아니면 현재 나눠준 경우를 지우고 다시 셔플 준비
		if (ansList == ShuffleCardList)
		{
			hit = true;
			break;
		}

		//셔플 횟수 카운트
		ans++;

		//셔플 진행
		for (int i = 0; i < N; i++)
		{
			ShuffleCardList[i] = JustBeforeTheShuffleCardList[Shuffle[i]];
		}

		//셔플 직후 처음과 같은 리스트로 나타나면 한바퀴 도는 것임으로 스톱
		if (ans == N - 1) break;
	}

	//만약 같은 것이 반복되는 경우일 경우 -1 출력
	if (!hit) 
		ans = -1;

	cout << ans;
}
