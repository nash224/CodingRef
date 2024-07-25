// Programmers_1845.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <vector>
#include <set>

int solution(std::vector<int> nums);

int main()
{
    std::cout << "Hello World!\n";
}


// 단순히 중복키를 허용하지 않는 set에 넣으면 종류의 수를 구할 수 잇음
// 1. 모든 포켓몬을 순회하면서 set에 넣어 Size를 구함
// 2. Size와 뽑을 수 있는 수를 비교하여 정답도출
int solution(std::vector<int> nums)
{
	int answer = 0;

	const int NUMBER_OF_POCKETS = static_cast<int>(nums.size());
	const int PICK_COUNT = NUMBER_OF_POCKETS / 2;

	std::set<int> PocketList;
	for (int Elem : nums)
	{
		PocketList.insert(Elem);
	}

	const int TYPE_COUNT = static_cast<int>(PocketList.size());

	answer = TYPE_COUNT < PICK_COUNT ? TYPE_COUNT : PICK_COUNT;

	return answer;
}