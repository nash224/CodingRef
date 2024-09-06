// Programmers_76501.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

// 변환기
int ConvertSign(int _Num, bool _bValue)
{
	return _Num *= _bValue ? 1 : -1;
}

int solution(std::vector<int> absolutes, std::vector<bool> signs) 
{
	int answer = 0;

	const int NUMBER_OF_SIZE = static_cast<int>(absolutes.size());

	for (int i = 0; i < NUMBER_OF_SIZE; i++)
	{
		answer += ConvertSign(absolutes[i], signs[i]);
	}

	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
