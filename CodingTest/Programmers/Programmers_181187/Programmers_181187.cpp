// Programmers_181187.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

using int64_t = long long;

int64_t GetDotInner(int _r1);
int64_t GetDotOuter(int _r2);

int64_t solution(int r1, int r2) 
{
	int64_t answer = 0;
	const int64_t OUTER_DOT_COUNT = GetDotOuter(r2);
	const int64_t Inner_DOT_COUNT = GetDotInner(r1);
	answer = OUTER_DOT_COUNT - Inner_DOT_COUNT;
	return answer;
}

int main()
{
	std::cout << solution(2, 3);
}

int64_t GetDotInner(int _r1)
{
	const int64_t Root = static_cast<int64_t>(_r1 * 2 - 1);
	return Root * Root;
}

int64_t GetDotOuter(int _r2)
{
	int64_t ReturnValue = 0;

	const int64_t InnerCount = GetDotInner(_r2);

	int YOffset = _r2;
	int OuterLineCout = 1;
	for (int x = 1; x < _r2; x++)
	{
		for (int y = YOffset; 0 < y; --y)
		{
			const int Len = (x * x + y * y);
			if (_r2 < YDot)
			{
				continue;
			}
			else if (YDot == _r2)
			{
				OuterLineCout++;
			}
			else
			{
				YOffset = y + 1;
			}

			break;
		}
	}

	ReturnValue = static_cast<int64_t>(OuterLineCout) * 4 + InnerCount;

	return ReturnValue;
}