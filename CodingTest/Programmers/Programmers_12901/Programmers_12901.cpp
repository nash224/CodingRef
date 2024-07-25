// Programmers_12901.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>


int GetDayToMonth(int _M)
{
	if (2 == _M)
	{
		return 29;
	}
	if (
		_M == 1 ||
		_M == 3 ||
		_M == 5 ||
		_M == 7 ||
		_M == 8 ||
		_M == 10 ||
		_M == 12
		)
	{
		return 31;
	}

	return 30;
}

int FromDay(int _M, int _D)
{
	int Total = 0;
	// 모든 일수를 더한다.
	for (int i = 1; i < _M; i++)
	{
		Total += GetDayToMonth(i);
	}

	Total += _D - 1;
	return Total;
}

std::string GetWeekDay(int _Num)
{
	switch (_Num)
	{
	case 0: return "SUN";
	case 1: return "MON";
	case 2: return "TUE";
	case 3: return "WED";
	case 4: return "THU";
	case 5: return "FRI";
	case 6: return "SAT";
	}

	return "NULL";
}

std::string solution(int a, int b)
{
	std::string answer = "";

	const int TotalDay = FromDay(a, b);
	const int NUMBER_OF_DAY = (TotalDay + 5) % 7;

	answer = GetWeekDay(NUMBER_OF_DAY);

	return answer;
}

int main()
{
	solution(5, 24);
    std::cout << "Hello World!\n";
}
