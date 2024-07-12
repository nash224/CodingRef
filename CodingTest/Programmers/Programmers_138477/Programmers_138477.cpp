
#include <iostream>
#include <string>
#include <vector>
#include <set>

// 단순 확인용
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
	// 자동 정렬 자료구조를 선택한다.
	// 중복되는 값이 존재함으로 MultiSet 선택
	// 자동으로 정렬된 구조에서 상위 3개의 수만 선택한다.

	// TODOLIST : 매번 정렬하는데 많은 시간이 걸릴 것 이다.
	// 따라서 하위 3개의 값은 제외해줄 필요가 있어보인다.
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
