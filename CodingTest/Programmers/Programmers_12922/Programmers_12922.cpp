// Programmers_12922.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>


std::string solution(int n);
int main()
{
	std::cout << solution(4);
}

std::string  solution(int n)
{
	std::string answer;
	answer.reserve(n *2);

	int iLoopCount = 0;

	while (iLoopCount != n)
	{
		answer += iLoopCount % 2 ? "박" : "수";
		++iLoopCount;
	}

	return answer;
}