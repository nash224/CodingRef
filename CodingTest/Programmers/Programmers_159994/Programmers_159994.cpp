// Programmers_159994.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

constexpr const int NOT_VALUE = -1;

std::string solution(std::vector<std::string> cards1, std::vector<std::string> cards2, std::vector<std::string> goal)
{
	// Init
	std::unordered_map<std::string, int> Dics;
	Dics.reserve(goal.size());

	for (int i = 0; i < static_cast<int>(goal.size()); i++)
	{
		Dics.insert(std::make_pair(goal[i], i));
	}

	std::queue<int> Pipe1;
	for (const std::string& Name : cards1)
	{
		std::unordered_map<std::string, int>::const_iterator FindIter = Dics.find(Name);
		if (Dics.end() == FindIter)
		{
			Pipe1.push(NOT_VALUE);
			continue;
		}

		Pipe1.push(FindIter->second);
	}

	std::queue<int> Pipe2;
	for (const std::string& Name : cards2)
	{
		std::unordered_map<std::string, int>::const_iterator FindIter = Dics.find(Name);
		if (Dics.end() == FindIter)
		{
			Pipe2.push(NOT_VALUE);
			continue;
		}

		Pipe2.push(FindIter->second);
	}

	// Run
	bool bResult = true;
	for (int i = 0; i < static_cast<int>(goal.size()); i++)
	{
		if (false == Pipe1.empty())
		{
			if (i == Pipe1.front())
			{
				Pipe1.pop();
				continue;
			}
		}

		if (false == Pipe2.empty())
		{
			if (i == Pipe2.front())
			{
				Pipe2.pop();
				continue;
			}
		}

		bResult = false;
		break;
	}

	return bResult ? "Yes" : "No";
}

int main()
{
	solution({ "i", "see", "to" }, { "you", "now", "me" }, { "i", "see", "now", "me" });
    std::cout << "Hello World!\n";
}
