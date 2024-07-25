// Programmers_134240.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

void FillNumber(std::string* _Result, int _Number, int _Loop)
{
	if (nullptr == _Result)
	{
		return;
	}

	for (int i = 0; i < _Loop; i++)
	{
		_Result->push_back(static_cast<char>(_Number) + '0');
	}
}

void Recursive(std::string* _Result, const std::vector<int>& food, int _Level)
{
	if (_Level == static_cast<int>(food.size()))
	{
		FillNumber(_Result, 0, 1);
		return;
	}

	if (0 != _Level)
	{
		FillNumber(_Result, _Level, food.at(_Level) / 2);
	}
	Recursive(_Result, food, _Level + 1);
	if (0 != _Level)
	{
		FillNumber(_Result, _Level, food.at(_Level) / 2);
	}
}

std::string solution(std::vector<int> food) 
{
	std::string answer = "";
	Recursive(&answer, food, 0);
	return answer;
}

int main()
{
	solution({ 1, 3, 4, 6 });
    std::cout << "Hello World!\n";
}
