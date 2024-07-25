// Programmers_169198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdarg.h>

std::vector<int> solution(int m, int n, int startX, int startY, std::vector<std::vector<int>> balls);

#define MAXINT static_cast<int>(static_cast<unsigned int>(-1) / 2)

int Pow(int _Value) { return _Value * _Value; }
int Abs(int _Value) { return _Value < 0 ? -_Value : _Value; }
int Min(const std::vector<int>& _Nums)
{
	int result = MAXINT;
	for (int Num : _Nums)
	{
		result = result < Num ? result : Num;
	}

	return result;
}
struct Ball
{
	int X = 0;
	int Y = 0;
};

class CBoard
{
public:
	CBoard(int _m, int _n, const Ball& _StartBall)
		: WIDTH(_m),HEIGHT(_n)
	{
		m_StartBall = _StartBall;
	}

public:
	// 84   48  84  48
	// 11 , 13, 73, 71
	int GetDistance(int _X, int _Y)
	{
		static std::vector<int> Temp(4, 0);
		Temp[0] = UpBounce(_X, _Y);
		Temp[1] = DownBounce(_X, _Y);
		Temp[2] = LeftBounce(_X, _Y);
		Temp[3] = RightBounce(_X, _Y);
		const int MAX_NUM = Min(Temp);
		return MAX_NUM;
	}

private:
	int RotateBoard()
	{

	}

	int UpBounce(int _X, int _Y)
	{
		if (true == IsVerticalLine(_X))
		{
			return MAXINT;
		}

		return Pow((HEIGHT * 2) - m_StartBall.Y - _Y) + Pow(Abs(_X - m_StartBall.X));
	}

	int DownBounce(int _X, int _Y)
	{
		if (true == IsVerticalLine(_X))
		{
			return MAXINT;
		}

		return Pow(m_StartBall.Y + _Y) + Pow(Abs(_X - m_StartBall.X));
	}

	int LeftBounce(int _X, int _Y)
	{
		if (true == IsHorizonLine(_Y))
		{
			return MAXINT;
		}

		return Pow(m_StartBall.X + _X) + Pow(Abs(_Y - m_StartBall.Y));
	}
	int RightBounce(int _X, int _Y)
	{
		if (true == IsHorizonLine(_Y))
		{
			return MAXINT;
		}

		return Pow((WIDTH * 2) - m_StartBall.X - _X) + Pow(Abs(_Y - m_StartBall.Y));
	}

	bool IsHorizonLine(int _Y) const
	{
		return (m_StartBall.Y == _Y);
	}

	bool IsVerticalLine(int _X) const
	{
		return (m_StartBall.X == _X);
	}

	bool IsDiagonal(int _X, int _Y) const
	{
		return (m_StartBall.X == _X) || (m_StartBall.Y == _Y);
	}

	bool IsReverseDiagonal(int _X, int _Y) const
	{
		return (m_StartBall.X == _Y) || (m_StartBall.Y == _Y);
	}

private:
	Ball m_StartBall;
	int WIDTH = 0;
	int HEIGHT = 0;

};

int main()
{
	solution(10, 10, 3, 7, { {7,7},{2,7},{7,3} });
    std::cout << "Hello World!\n";
}

std::vector<int> solution(int m, int n, int startX, int startY, std::vector<std::vector<int>> balls)
{
	std::vector<int> answer;
	answer.reserve(balls.size());

	CBoard NewBoard(m, n, {startX, startY});

	for (const std::vector<int>& Ball : balls)
	{
		const int DISTANCE = NewBoard.GetDistance(Ball[0], Ball[1]);
		answer.push_back(DISTANCE);
	}

	return answer;
}