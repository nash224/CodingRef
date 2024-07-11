
#include <string>
#include <vector>
#include <cmath>

int MakeBit(int _Value);

std::vector<int> solution(int l, int r) 
{
	std::vector<int> answer;

	for (int i = l; i <= r; i++)
	{
		std::string StrNum = std::to_string(i);

		bool bCheck = true; 
		for (const char CHAR_NUM : StrNum)
		{
			if ('0' != CHAR_NUM && '5' != CHAR_NUM)
			{
				bCheck = false;
				break;
			}
		}

		if (true == bCheck)
		{
			answer.push_back(i);
		}
	}

	if (true == answer.empty())
	{
		answer.push_back(-1);
	}


	const int L_VALUE = MakeBit(l);
	const int R_VALUE = MakeBit(r);

	if (L_VALUE == R_VALUE)
	{

	}

	for (int i = L_VALUE; i <= R_VALUE; i++)
	{
		if (0 == i)
		{
			continue;
		}

		int iBit = i;
		int iNum = 0;
		int iLoopCount = 0;

		while (0 != iBit)
		{
			if (iBit % 2)
			{
				iNum += std::pow(10, iLoopCount) * 5;
			}

			iBit /= 2;

			++iLoopCount;
		}

		answer.push_back(iNum);
	}

	if (true == answer.empty())
	{
		answer.push_back(-1);
	}

	return answer;
}

int main()
{
	solution(1, 5);
}

int MakeBit(int _Value)
{
	int ReturnValue = 0;

	std::string IString = std::to_string(_Value);
	const int SIZE = static_cast<int>(IString.size());

	for (int i = 0; i < SIZE; i++)
	{
		const char CHAR_NUM = IString[i];
		const int INT_NUM = static_cast<int>(CHAR_NUM) - '0';
		const int iBit = INT_NUM / 5;

		if (0 == iBit)
		{
			for (int j = i + 1; j < SIZE; j++)
			{
				IString[j] = '5';
			}
		}
		else
		{
			ReturnValue += static_cast<int>(std::pow(2, SIZE - i - 1));
		}
	}

	return ReturnValue;
}

