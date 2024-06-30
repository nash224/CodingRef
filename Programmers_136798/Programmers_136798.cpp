// Programmers_136798.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

class CPowerConvention
{
public:
	CPowerConvention(int _iLimit, int _iReflection)
		:mLimit(_iLimit), mReflection(_iReflection)
	{

	}

public:
	int GetPower(int _iNumber);

protected:
	bool IsOverPower(int _iPower) const
	{
		return mLimit < _iPower;
	}

private:
	const int mLimit;
	const int mReflection;

};

int solution(int number, int limit, int power) 
{
	// 협약 생성
	CPowerConvention NewConvention{ limit, power };

	int answer = 0;

	// Solve
	for (int iKnight_Number = 1; iKnight_Number <= number; iKnight_Number++)
	{
		answer += NewConvention.GetPower(iKnight_Number);
	}

	return answer;
}

int main()
{
	std::cout << solution(10, 3, 2);
}

int CPowerConvention::GetPower(int _iNumber)
{
	std::queue<int> Que;

	for (int i = 2; i <= _iNumber; i++)
	{
		int iFactor = 0;
		// 인수 찾음
		while (0 == _iNumber % i)
		{
			_iNumber /= i;

			++iFactor;
		}

		if (0 != iFactor)
		{
			Que.push(iFactor);
		}
	}

	int iDivisor = 1;

	while (false == Que.empty())
	{
		int iFactor = Que.front();
		Que.pop();

		iDivisor *= iFactor + 1;
	}

	// 예외처리
	if (true == IsOverPower(iDivisor))
	{
		iDivisor = mReflection;
	}

	return iDivisor;
}