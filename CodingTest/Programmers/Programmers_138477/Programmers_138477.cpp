
#include <iostream>
#include <string>
#include <vector>
#include <set>

void Print(std::vector<int>&& _vec)
{
	for (int Elem : _vec)
	{
		std::cout << Elem << ' ';
	}
}

std::vector<int> solution(int k, std::vector<int> score);

int main()
{
	std::vector<int> Input{ 10, 100, 20, 150, 1, 100, 200 };
	Print(solution(3, { 10, 100, 20, 150, 1, 100, 200 }));
}


std::vector<int> solution(int k, std::vector<int> score)
{
	std::vector<int> answer;
	answer.reserve(score.size());
	std::multiset<int, std::greater<int>> Stage;

	for (int Elem : score)
	{
		Stage.insert(Elem);
		int Index = std::min(static_cast<int>(Stage.size()), k) - 1;
		std::set<int>::iterator StartIter = Stage.begin();
		for (int i = 0; i < Index; i++)
		{
			++StartIter;
		}

		answer.push_back(*StartIter);
	}
		
	return answer;
}
