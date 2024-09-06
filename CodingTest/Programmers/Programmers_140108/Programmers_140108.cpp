// Programmers_140108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

#define RESET_CHAR ' '

// 이제 이 문자열을 왼쪽에서 오른쪽으로 읽어나가면서, 
// x와 x가 아닌 다른 글자들이 나온 횟수를 각각 셉니다.
// 처음으로 두 횟수가 같아지는 순간 멈추고, 지금까지 읽은 문자열을 분리합니다.

// s에서 분리한 문자열을 빼고 남은 부분에 대해서 이 과정을 반복합니다. 
// 남은 부분이 없다면 종료합니다.

// 만약 두 횟수가 다른 상태에서 더 이상 읽을 글자가 없다면, 
// 역시 지금까지 읽은 문자열을 분리하고, 종료합니다.

// pseudocode
// 한 단위 기준으로 처리된다.
// 단위의 기준은 첫글자 수와 다른 글자의 수가 같아지면 분리한다.
// 그리고 위를 반복한다.

int solution(std::string s) 
{
	int answer = 0;

	const int STRING_SIZE = static_cast<int>(s.size());

	std::vector<std::string> Result;

	int Offset = 0;
	int EndPoint = 0;
	int FirstCharCount = 0;
	int OtherCharCount = 0;
	char FirstChar = RESET_CHAR;

	// Offset이 String의 EndPoint지점에 도달했을 경우, 빠져나온다.
	while (Offset < STRING_SIZE)
	{
		// 초기화되면 새로운 문자를 저장한다.
		if (RESET_CHAR == FirstChar)
		{
			FirstChar = s.at(Offset);
		}

		// 현재 문자와 다르면 OtherCharCount를 증가한다.
		char CurChar = s.at(Offset);
		if (CurChar != FirstChar)
		{
			++OtherCharCount;
			if (OtherCharCount == FirstCharCount)
			{
				FirstCharCount = 0;
				OtherCharCount = 0;
				FirstChar = RESET_CHAR;
				++answer;

				// 확인용
				const std::string Text = s.substr(EndPoint, Offset);
				Result.push_back(Text);
				EndPoint = Offset + 1;
			}
		}
		else
		{
			++FirstCharCount;
		}

		++Offset;
	}

	if (Offset != EndPoint)
	{
		const std::string Text = s.substr(EndPoint, Offset);
		Result.push_back(Text);
		++answer;
	}

	return answer;
}

int main()
{
	// solution("aaabbaccccabba");
	solution("abracadabra");
    std::cout << "Hello World!\n";
}
