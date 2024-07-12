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
	// <=============== Dictionary Setting =================>
	std::unordered_map<std::string, int> Dic;

	for (size_t i = 0; i < players.size(); i++)
	{
		Dic.insert(std::pair(players[i], static_cast<int>(i)));
	}

	// unordered_map은 Hash변환 시간이 있지만 대용량 리소스를 Array담아 Key로 찾기 때문에 참조시간을 아낄 수 있다.
	// Calling된 선수의 위치와 그 앞의 선수 위치를 umap에서 바꿔준다 
	// 그리고 그 앞의 선수의 이름을 찾아 Dictionay의 위치를 동기화 해준다.
	// 동기화는 단순 위치만 바뀌기 때문에 바뀐 선수만 교체해준다.
	for (std::string_view Name : callings)
	{
		std::unordered_map<std::string, int>::iterator FindIter = Dic.find(Name.data());
		int Prev = FindIter->second -= 1;

		std::string_view PrevPlayer = players[Prev];
		FindIter = Dic.find(PrevPlayer.data());
		FindIter->second += 1;

		// Std::swap은 이동 연산자를 사용한다. 따라서 단순 복사(얕은 복사)만 일어나기 때문에 복사비용을 아낄 수 있다.
		std::swap(players[Prev] , players[Prev + 1]);
	}
	 
	return players;
}