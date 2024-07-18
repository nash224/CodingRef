// Programmers_42576.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
// #include <xhash> (프로그래머스에서 헤더지원 안함)
#include <algorithm>

// 1안 Unordered_map Dics 사용
// n번 순회를 돌면서 hash로 변환하는 비용
// n번 Completion n번 순회 돌면서 hash key값으로 umap 상수 접근 비용
// 이론상 an+bn

// 2안 키값을 hash로 정렬한 후, 순회를 돌면서 탈락자 찾는 방법
// 정렬 비용 + 최악의 비용 n번
// 테스트 4 〉	통과 (235.36ms, 25.4MB)
// 테스트 5 〉	실패 (시간 초과)

std::string HashSolution(std::vector<std::string> participant, std::vector<std::string> completion);
std::string UmapSolution(std::vector<std::string> participant, std::vector<std::string> completion);

int main()
{
	std::cout << UmapSolution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });
}

bool HashTo(std::string_view _Str1, std::string_view _Str2)
{
	return std::hash<std::string>{}(_Str1.data()) < std::hash<std::string>{}(_Str2.data());
}

std::string UmapSolution(std::vector<std::string> participant, std::vector<std::string> completion)
{
	std::string answer = "";

	std::unordered_multimap<std::string, bool> Dics;
	Dics.reserve(participant.size());
	for (std::string_view PlayerName : participant)
	{
		Dics.insert(std::make_pair<std::string, bool>(PlayerName.data(), false));
	}

	for (std::string_view Name : completion)
	{
		std::unordered_multimap<std::string, bool>::iterator FindIter = Dics.find(Name.data());
		if (true == FindIter->second)
		{
			++FindIter;
			continue;
		}

		FindIter->second = true;
	}

	for (const std::pair<std::string, bool>& pair : Dics)
	{
		if (false == pair.second)
		{
			answer = pair.first;
			break;
		}
	}

	return answer;
}

std::string HashSolution(std::vector<std::string> participant, std::vector<std::string> completion)
{
	std::string answer = "";

	std::sort(completion.begin(), completion.end(), [](std::string_view _Str1, std::string_view _Str2)
		{
			return HashTo(_Str1, _Str2);
		});
	std::sort(participant.begin(), participant.end(), [](std::string_view _Str1, std::string_view _Str2)
		{
			return HashTo(_Str1, _Str2);
		});

	const int SIZE = static_cast<int>(participant.size());

	for (int i = 0; i < SIZE; i++)
	{
		if (completion[i] != participant[i])
		{
			answer = participant[i];
			break;
		}
	}

	return answer;
}