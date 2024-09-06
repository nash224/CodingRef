// Programmers_118666.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

int Abs(int _Num)
{
	return (_Num < 0) ? -_Num : _Num;
}

std::string solution(std::vector<std::string> survey, std::vector<int> choices) 
{
	std::string answer = "";

	// 각 성격 유형의 점수
	std::map<char, int> Score;

	const int SURVEY_SIZE = static_cast<int>(survey.size());

	for (int i = 0; i < SURVEY_SIZE; i++)
	{
		if (choices[i] < 4)
		{
			Score[survey[i][0]] += Abs(choices[i] - 4);
		}
		else
		{
			Score[survey[i][1]] += Abs(4 - choices[i]);
		}
	}

	answer.push_back(Score['T'] <= Score['R'] ? 'R' : 'T');
	answer.push_back(Score['F'] <= Score['C'] ? 'C' : 'F');
	answer.push_back(Score['M'] <= Score['J'] ? 'J' : 'M');
	answer.push_back(Score['N'] <= Score['A'] ? 'A' : 'N');
	
	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
