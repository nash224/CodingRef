// BJ_17478.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#define FIRST_CONVERSATION R"(어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.)"
#define QUESTION R"("재귀함수가 뭔가요?")"
#define ANSWER_LINE1 R"("잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.)"
#define ANSWER_LINE2 "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." 
#define ANSWER_LINE3 R"(그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.")"
#define ANSWER_LINE4 R"("재귀함수는 자기 자신을 호출하는 함수라네")"


#define RECURSIVE_INLINE "____"
#define END_REMARK "라고 답변하였지."

void Recursive_GetStory(std::string* _Str, const int& _N, int _CallCount);

int main()
{
	int N;
	std::cin >> N;

	std::string Answer;
	Answer.append(FIRST_CONVERSATION);
	Answer.append("\n");
	Recursive_GetStory(&Answer, N, 0);
    std::cout << Answer;
}

void AppendLine(std::string* _Str, int _Count, bool _bNewLine = false)
{
	for (int i = 0; i < _Count; i++)
	{
		(*_Str).append(RECURSIVE_INLINE);
	}
}

void Recursive_GetStory(std::string* _Str, const int& _N, int _CallCount)
{
	++_CallCount;

	AppendLine(_Str, _CallCount - 1);
	(*_Str).append(QUESTION);
	(*_Str).append("\n");

	const bool bRecursiveEnd = (_CallCount - 1 == _N);
	if (false == bRecursiveEnd)
	{
		AppendLine(_Str, _CallCount - 1);
		(*_Str).append(ANSWER_LINE1);
		(*_Str).append("\n");
		AppendLine(_Str, _CallCount - 1);
		(*_Str).append(ANSWER_LINE2);
		(*_Str).append("\n");
		AppendLine(_Str, _CallCount - 1);
		(*_Str).append(ANSWER_LINE3);
		(*_Str).append("\n");

		Recursive_GetStory(_Str, _N, _CallCount);
	}
	else
	{
		AppendLine(_Str, _CallCount - 1);
		(*_Str).append(ANSWER_LINE4);
		(*_Str).append("\n");
	}

	AppendLine(_Str, _CallCount - 1);
	(*_Str).append(END_REMARK);
	(*_Str).append("\n");
}
