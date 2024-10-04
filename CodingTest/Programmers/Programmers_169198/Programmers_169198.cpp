// Programmers_169198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/* 컴파일 타임에 연산한 결과를 상수로 정의한다. */
constexpr int MAX_INT = static_cast<int>(static_cast<unsigned int>(-1) / 2);
#define MAX MAX_INT;

int min(int _a, int _b)
{
	return (_a > _b ? _b : _a);
}

/**
*	일반적인 원쿠션은 피타고라스 방정식으로 해결했으며 
*	동일한 축에 존재하고 목표를 가로질러 원쿠션할 경우, 별도 처리를 수행했다.
*	대각선이 될 경우는 거리상으로 평면보다 더 멀기 때문에 존재하지 않는다고 가정한다.
* */
int CalculateDistance(int _m, int _n, int _StartX, int _StartY, int _TargetX, int _TargetY)
{
	int Result = MAX;

	// 동일한 X축에 존재하지 않을 경우
	if (_StartX != _TargetX)
	{
		Result = min(Result, static_cast<int>(std::pow(_StartX - _TargetX, 2) + std::pow(_StartY + _TargetY, 2)));
		Result = min(Result, static_cast<int>(std::pow(_StartX - _TargetX, 2) + std::pow(2 * _n - _StartY - _TargetY, 2)));
	}
	else
	{
		// 동일한 X축에 존재하면서 목표가 위에 있을 경우
		if (_StartY < _TargetY)
		{
			Result = min(Result, static_cast<int>(std::pow(_StartY + _TargetY, 2)));
		}
		else
		{
			Result = min(Result, static_cast<int>(std::pow(2 * _n - _StartY - _TargetY, 2)));
		}
	}

	// 동일한 Y축에 존재하지 않을 경우
	if (_StartY != _TargetY)
	{
		Result = min(Result, static_cast<int>(std::pow(_StartX + _TargetX, 2) + std::pow(_StartY - _TargetY, 2)));
		Result = min(Result, static_cast<int>(std::pow(2 * _m - _StartX - _TargetX, 2) + std::pow(_StartY - _TargetY, 2)));
	}
	else
	{
		// 동일한 Y축에 존재하면서 목표가 오른쪽에 있을 경우
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
