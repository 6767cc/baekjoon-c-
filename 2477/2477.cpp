#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
	int K, a, b, big_area, small_area;
	vector <pair<int, int>> map;

	cin >> K;

	for (int i = 0; i < 6; i++)
	{
		cin >> a >> b;
		map.push_back(pair<int, int>(a, b));
	}

	for (int i = 0; i < 6; i++)
	{
		map.push_back(map[i]);
	}

	for (int i = 3; i < 12; i++) 
	{
		if (map[i].first == map[i - 2].first && map[i - 1].first == map[i - 3].first) 
		{
			big_area = map[i + 1].second * map[i + 2].second;
			small_area = map[i - 1].second * map[i - 2].second;
			break;
		}
	}

	cout << K * (big_area - small_area);

	return 0;
}