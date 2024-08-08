// Programmers_131705.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

int solution(std::vector<int> number) 
{
	int answer = 0;

	const int SIZE = static_cast<int>(number.size());

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (int k = j; k < SIZE; k++)
			{
				if (k == j || k == i)
				{
					continue;
				}

				if (0 == number[i] + number[j] + number[k])
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
	solution({ -3, -2, -1, 0, 1, 2, 3 });
    std::cout << "Hello World!\n";
}
