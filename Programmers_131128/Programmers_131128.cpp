// Programmers_131128.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

std::string GetAnswer(std::string& _X, std::string& _Y);

std::string solution(std::string X, std::string Y)
{
	std::string answer = GetAnswer(X, Y);

	return answer;
}

int main()
{
	std::string TestString = "66665555222211";

	size_t FistNum = TestString.find_first_of('6');
	size_t LastNum = TestString.find_last_of('6');

	std::cout <<
		"First Number Index : " << FistNum <<
		"Last Number Index : " << LastNum;

	return 0 ;

    std::cout << solution("55532", "74316553") << '\n';
    std::cout << solution("65", "32") << '\n';
    std::cout << solution("10000", "50000") << '\n';
}

std::string GetAnswer(std::string& _X, std::string& _Y)
{
	std::string Answer;

	std::string XCopy{ _X };
	std::string YCopy{ _Y };

	std::sort(XCopy.begin(), XCopy.end(), std::greater<int>());
	std::sort(YCopy.begin(), YCopy.end(), std::greater<int>());

	for (char Char = '9'; '0' <= Char; --Char)
	{
		const size_t FIRST_OF_XCHAR_NUMBER = XCopy.find_first_of(Char);
		const size_t FIRST_OF_YCHAR_NUMBER = YCopy.find_first_of(Char);

		if (std::string::npos == FIRST_OF_XCHAR_NUMBER || std::string::npos == FIRST_OF_YCHAR_NUMBER)
		{
			continue;
		}

		const size_t LAST_OF_XCHAR_NUMBER = XCopy.find_last_of(Char);
		const size_t LAST_OF_YCHAR_NUMBER = YCopy.find_last_of(Char);

		int Index = 0;
		int XOFFSET = static_cast<int>(LAST_OF_XCHAR_NUMBER - FIRST_OF_XCHAR_NUMBER + 1);
		int YOFFSET = static_cast<int>(LAST_OF_YCHAR_NUMBER - FIRST_OF_YCHAR_NUMBER + 1);
		int CharCount = std::min(YOFFSET, XOFFSET);

		for (int i = 0; i < CharCount; i++)
		{
			Answer.push_back(Char);
		}
	}

	if (true == Answer.empty())
	{
		Answer = "-1";
	}
	else if ('0' == Answer.at(0))
	{
		Answer = "0";
	}

	return std::move(Answer);
}