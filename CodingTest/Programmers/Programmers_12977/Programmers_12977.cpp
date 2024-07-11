// Programmers_12977.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

bool IsPrineNumber(int _Num);

int solution(std::vector<int> nums) 
{
	int answer = 0;

	std::vector<int> Evens;
	std::vector<int> Odds;

	Evens.reserve(nums.size());
	Odds.reserve(nums.size());

	for (int Num : nums)
	{
		if (0 == Num % 2)
		{
			Evens.push_back(Num);
		}
		else
		{
			Odds.push_back(Num);
		}
	}

	// 짝짝짝 x
	// 짝짝홀 o
	// 짝홀홀 x
	// 홀홀홀 o

	for (size_t i = 0; i < Evens.size(); i++)
	{
		for (size_t j = i + 1; j < Evens.size(); j++)
		{
			for (size_t k = 0; k < Odds.size(); k++)
			{
				int Sum = Evens[i] + Evens[j] + Odds[k];
				if (true == IsPrineNumber(Sum))
				{
					++answer;
				}
			}
		}
	}

	for (size_t i = 0; i < Odds.size(); i++)
	{
		for (size_t j = i + 1; j < Odds.size(); j++)
		{
			for (size_t k = j + 1; k < Odds.size(); k++)
			{
				int Sum = Odds[i] + Odds[j] + Odds[k];
				if (true == IsPrineNumber(Sum))
				{
					++answer;
				}
			}
		}
	}


	return answer;
}

int main()
{
	std::cout << solution({ 1,2,7,6,4 }) << '\n';
}

bool IsPrineNumber(int _Num)
{
	for (int i = 3; i < _Num / 2; i++)
	{
		if (0 == _Num % i)
		{
			return false;
		}
	}

	return true;
}