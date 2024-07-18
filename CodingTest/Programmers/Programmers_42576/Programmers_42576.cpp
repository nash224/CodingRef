// Programmers_42576.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include <algorithm>

std::string UmapSolution(std::vector<std::string> participant, std::vector<std::string> completion);

int main()
{
	std::cout << UmapSolution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });
}

std::string UmapSolution(std::vector<std::string> participant, std::vector<std::string> completion)
{
	std::string answer = "";
	// 정렬해서 순서가 어긋나면 완주하지 못한 플레이어임
	std::sort(completion.begin(), completion.end());
	std::sort(participant.begin(), participant.end());

	size_t EndSize = participant.size() - 1;
	for (size_t i = 0; i < participant.size(); i++)
	{
		// 마지막 배열 Access 예외처리
		if (EndSize == i)
		{
			answer = participant[i];
			break;
		}
		if (participant[i] == completion[i])
		{
			continue;
		}
		
		answer = participant[i];
		break;
	}

	return answer;
}