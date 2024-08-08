// Programmers_86491.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> sizes)
{
	int answer = 0;

	std::vector<int> WidthList;
	std::vector<int> HeightList;
	WidthList.reserve(sizes.size());
	HeightList.reserve(sizes.size());

	for (std::vector<int>& Size : sizes)
	{
		if (Size[0] < Size[1])
		{
			std::swap(Size[0], Size[1]);
		}
		WidthList.push_back(Size[0]);
		HeightList.push_back(Size[1]);
	}

	std::sort(WidthList.begin(), WidthList.end(), std::greater<int>());
	std::sort(HeightList.begin(), HeightList.end(), std::greater<int>());

	return WidthList[0] * HeightList[0];
}

int main()
{
    std::cout << "Hello World!\n";
}
