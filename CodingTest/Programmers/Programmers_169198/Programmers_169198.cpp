// Programmers_169198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MAX static_cast<unsigned int>(-1) / 2;

int min(int _a, int _b)
{
	return (_a > _b ? _b : _a);
}

int CalculateDistance(int _m, int _n, int _StartX, int _StartY, int _TargetX, int _TargetY)
{
	int Result = MAX;

	if (_StartX != _TargetX)
	{
		Result = min(Result, static_cast<int>(std::pow(_StartX - _TargetX, 2) + std::pow(_StartY + _TargetY, 2)));
		Result = min(Result, static_cast<int>(std::pow(_StartX - _TargetX, 2) + std::pow(2 * _n - _StartY - _TargetY, 2)));
	}
	else
	{
		if (_StartY < _TargetY)
		{
			Result = min(Result, static_cast<int>(std::pow(_StartY + _TargetY, 2)));
		}
		else
		{
			Result = min(Result, static_cast<int>(std::pow(2 * _n - _StartY - _TargetY, 2)));
		}
	}

	if (_StartY != _TargetY)
	{
		Result = min(Result, static_cast<int>(std::pow(_StartX + _TargetX, 2) + std::pow(_StartY - _TargetY, 2)));
		Result = min(Result, static_cast<int>(std::pow(2 * _m - _StartX - _TargetX, 2) + std::pow(_StartY - _TargetY, 2)));
	}
	else
	{
		if (_StartX < _TargetX)
		{
			Result = min(Result, static_cast<int>(std::pow(_StartX + _TargetX, 2)));
		}
		else
		{
			Result = min(Result, static_cast<int>(std::pow(2 * _m - _StartX - _TargetX, 2)));
		}
	}

	return Result;
}

std::vector<int> solution(int m, int n, int startX, int startY, std::vector<std::vector<int>> balls) 
{
	std::vector<int> answer;
	answer.reserve(balls.size());

	for (const std::vector<int>& Ball : balls)
	{
		const int Distance = CalculateDistance(m, n, startX, startY, Ball.at(0), Ball.at(1));
		answer.push_back(Distance);
	}

	return answer;
}

int main()
{
	solution(10, 10, 3, 7, { {7,7},{2,7},{7,3} });
    std::cout << "Hello World!\n";
}
