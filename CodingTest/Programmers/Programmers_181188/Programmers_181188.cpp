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

// 모든 end 데이터를 오름차순으로 정렬하고 
// 지정했던 end값과 다음의 start값을 비교해서 start > end 라면 
// end의 위치를 start 값으로 갱신하고 새로운 미사일을 쏜다. 
int solution(std::vector<std::vector<int>> targets)
{
	int answer = 0;

	// 정렬
	std::sort(targets.begin(), targets.end(), cmp);

	// 첫번째 원소 end값 지정
	int e = targets[0][1];
	answer++;

	for (const std::vector<int>& target : targets)
	{
		int s = target.at(0);
		if (e <= s)
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