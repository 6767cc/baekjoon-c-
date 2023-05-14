// 2910.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m, r; //n,m은 첫째줄 r은 둘째줄
map<int, int> Map; // 값 저장
map <int, int> order; // 순서

bool crit(pair<int, long int> a, pair<int, long int> b)
{
	if (a.second == b.second)
		return order[a.first] < order[b.first];

	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> r;
		Map[r]++;

		if (order[r] == 0)
			order[r] = i + 1;
	}

	vector<pair<int, int>> vec(Map.begin(), Map.end());

	//vec.second에 따라 내림차순 정리
	sort(vec.begin(), vec.end(), crit);

	// vec.first를 vec.second 만큼 출력 반복
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].second; j++)
		{
			cout << vec[i].first << ' ';
		}
	}
}