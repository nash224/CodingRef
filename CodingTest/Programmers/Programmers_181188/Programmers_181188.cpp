// Programmers_181188.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool cmp(std::vector<int>& _v1, std::vector<int>& _v2)
{
	return _v1.at(1) < _v2.at(1);
}

int solution(std::vector<std::vector<int>> targets)
{
	int answer = 0;

	std::sort(targets.begin(), targets.end(), cmp);

	int e = targets[0][1];
	answer++;

	for (const std::vector<int>& target : targets)
	{
		int s = target.at(0);
		if (s < e)
		{
			continue;
		}
		else
		{
			e = target.at(1);
			answer++;
		}
	}


	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}