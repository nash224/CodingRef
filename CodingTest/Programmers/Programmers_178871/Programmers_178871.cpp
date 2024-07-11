// Programmers_178871.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings);

int main()
{
	solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });
    std::cout << "Hello World!\n";
}


std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings) 
{
	std::unordered_map<std::string, int> Dic;

	for (size_t i = 0; i < players.size(); i++)
	{
		Dic.insert(std::pair(players[i], static_cast<int>(i)));
	}

	for (std::string_view Name : callings)
	{
		std::unordered_map<std::string, int>::iterator FindIter = Dic.find(Name.data());
		int Prev = FindIter->second -= 1;

		std::string_view PrevPlayer = players[Prev];
		FindIter = Dic.find(PrevPlayer.data());
		FindIter->second += 1;
		std::swap(players[Prev] , players[Prev + 1]);
	}
	 
	return players;
}