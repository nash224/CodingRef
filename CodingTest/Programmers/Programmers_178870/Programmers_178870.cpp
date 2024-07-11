// Programmers_178870.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> sequence, int k);

int main()
{
	solution({ 1, 2, 3, 4, 5 }, 7);
    std::cout << "Hello World!\n";
}



std::vector<int> solution(std::vector<int> sequence, int k) 
{
	std::vector<int> answer(2);
	std::vector<std::pair<int, int>> Pairs;

	const int SIZE = static_cast<int>(sequence.size());


	int Total = 0;
	bool bFind = false;
	bool bLoop = true;

	for (int i = SIZE - 1; 0 <= i; --i)
	{
		Total = 0;

		for (int j = i; 0 <= j; --j)
		{
			Total += sequence[j];

			if (k == Total)
			{
				if (true == bFind)
				{
					int Prev = answer[1] - answer[0];
					int Cur = j - i;

					if (Prev < Cur)
					{
						bLoop = false;
						break;
					}
				}

				answer[0] = j;
				answer[1] = i;
				bFind = true;
				break;
			}
			else if (true == bFind)
			{
				bLoop = false;
				break;
			}
			else if (k < Total)
			{
				break;
			}
		}

		if (false == bLoop)
		{
			break;
		}
	}

	return answer;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
