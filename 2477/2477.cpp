// 2477.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <cmath>

using namespace std;

int convertIndex(int i)
{
	if (i == -1)return 5;
	if (i == 6) return 0;

	return i;
}

int main()
{
	freopen("입력.txt", "r", stdin);

	int n, result;
	int rectMax, rectMin, ri, ci; // 육각형 : 큰 직사각형(rectMax) - 작은 직사각형(rectMin), ri, ci : 큰 직사각형의 인덱스 저장 변수
	int RM = 0, CM = 0, rm, cm; // 큰 직사격형 가로 세로 : RM, CM, 작은 직사각형 가로, 세로 : rm, cm
	pair<int, int> p[6], rowMax, colMax;

	rectMin = 1;
	cin >> n;

	for (int i = 0; i < 6; i++) { // first : 1, 2 -> 가로, first : 3, 4 -> 세로
		cin >> p[i].first >> p[i].second;

		if (p[i].first < 3)RM = max(RM, p[i].second);
		else CM = max(CM, p[i].second);
	} // 입력 받으면서 큰 직사각형의 가로 세로 길이를 각 RM, Cm에 저장한다

	for (int i = 0; i < 6; i++) {
		if (p[i].second == RM && p[i].first < 3) {
			rowMax = p[i];
			ri = i;
		}
		else if (p[i].second == CM && p[i].first >= 3) {
			colMax = p[i];
			ci = i;
		}
	} // 큰 직사각형을 찾으며 해당 인덱스도 저장한다
	rectMax = rowMax.second * colMax.second;

	int r1 = convertIndex(ri - 1);
	int r2 = convertIndex(ri + 1);
	cm = abs(p[r1].second - p[r2].second);
	// 가장 긴 가로 길이와 연결된 세로 축은 참외 밭에 포함되는 축이기에 연결된 값의 절대값 차이가 작은 직사각형의 세로 길이

	int c1 = convertIndex(ci - 1);
	int c2 = convertIndex(ci + 1);
	rm = abs(p[c1].second - p[c2].second);
	// 가장 긴 세로 길이와 연결된 가로 축은 참외 밭에 포함되는 축이기에 연결된 값의 절대값 차이가 작은 직사각형의 가로 길이

	rectMin = cm * rm; // 작은 직사각형 크기
	result = (rectMax - rectMin) * n; // (큰 직사각형 - 작은 직사각형) * m^2당 참외 개수

	cout << result;

	return 0;
}