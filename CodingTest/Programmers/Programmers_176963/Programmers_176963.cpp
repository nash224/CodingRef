// Programmers_176963.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> solution(
	std::vector<std::string> name, 
	std::vector<int> yearning, 
	std::vector<std::vector<std::string>> photo
)
{
	std::vector<int> answer;

	const int NAME_SIZE = static_cast<int>(name.size());

	// 문자열을 비교하는 비용이 생각보다 많아서 Hash로 비교하는 HashMap 선택
	std::unordered_map<std::string, int> YearningList;
	YearningList.reserve(NAME_SIZE);

	// 리소스 
	for (int i = 0; i < NAME_SIZE; i++)
	{
		YearningList.insert(std::make_pair(name[i], yearning[i]));
	}

	int YearningScore = 0;

	// 모든 사진을 순회하면서 unordered_map에 있는 매핑된 점수로 각 사진의 추억 점수를 채점한다.
	for (const std::vector<std::string>& Picture : photo)
	{
		for (const std::string& Name : Picture)
		{
			std::unordered_map<std::string, int>::const_iterator FindIter = YearningList.find(Name);
			if (YearningList.end() == FindIter)
			{
				continue;
			}

			YearningScore += FindIter->second;
		}

		answer.push_back(YearningScore);
		YearningScore = 0;
	}

	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
