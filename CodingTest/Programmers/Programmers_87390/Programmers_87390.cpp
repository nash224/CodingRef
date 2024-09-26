// Programmers_87390.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<int> solution(int n, long long left, long long right)
{
	const int SIZE = static_cast<int>(right - left) + 1;
	const long long ARRAY_SIZE = static_cast<long long>(n);

	std::vector<int> answer;
	answer.reserve(SIZE);

	int X, Y, NUM = 0;
	for (long long i = left; i <= right; i++)
	{
		X = static_cast<int>(i % ARRAY_SIZE);
		Y = static_cast<int>(i / ARRAY_SIZE);
		NUM = (X < Y ? Y : X) + 1;
		answer.push_back(NUM);
	}

	return answer;
}

int main()
{
	solution(3, 2, 5);
    std::cout << "Hello World!\n";
}
