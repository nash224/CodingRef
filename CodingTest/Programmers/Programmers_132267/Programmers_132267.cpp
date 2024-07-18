// Programmers_132267.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

int solution(int a, int b, int n);

int main()
{
	std::cout << solution(3, 1, 20);
}

int solution(int _GiveCount, int _GetCount, int _Total)
{
	int answer = 0;

	while (_GiveCount <= _Total)
	{
		const int EXCHANGE_COUNT = _Total / _GiveCount;
		answer += EXCHANGE_COUNT * _GetCount;
		_Total -= EXCHANGE_COUNT * (_GiveCount - _GetCount);
	}

	return answer;
}