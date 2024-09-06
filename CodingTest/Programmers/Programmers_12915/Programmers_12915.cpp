// Programmers_12915.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> solution(std::vector<std::string> strings, int n) 
{
	std::sort(strings.begin(), strings.end(), [strings, n](const std::string& _Left, const std::string& _Right)
		{
			const char LEFT_CHAR = _Left.at(n);
			const char RIGHT_CHAR = _Right.at(n);

			if (LEFT_CHAR < RIGHT_CHAR)
			{
				return true;
			}
			else if (LEFT_CHAR == RIGHT_CHAR)
			{
				if (_Left < _Right)
				{
					return true;
				}

				return false;
			}
			
			return false;
		});

	return strings;
}

int main()
{
	solution({ "sun", "bed", "car" }, 1);
    std::cout << "Hello World!\n";
}