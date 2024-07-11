// Programmers_12912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


long long solution(int a, int b);

int main()
{
    std::cout << solution(600, -100000);
}

long long solution(int a, int b)
{
	using ReturnType = long long;
	ReturnType answer = 0;

	ReturnType MIN_VALUE = static_cast<ReturnType>(std::min(a, b));
	ReturnType MAX_VALUE = static_cast<ReturnType>(std::max(a, b));

	if (MIN_VALUE * MAX_VALUE < 0)
	{
		if (std::abs(MIN_VALUE) > std::abs(MAX_VALUE))
		{
			MAX_VALUE = MAX_VALUE * static_cast<ReturnType>(-1) - static_cast<ReturnType>(1);
		}
		else
		{
			MIN_VALUE = MIN_VALUE * static_cast<ReturnType>(-1) + static_cast<ReturnType>(1);
		}
	}

	for (ReturnType i = MIN_VALUE; i <= MAX_VALUE; i++)
	{
		answer += i;
	}

	return answer;
}