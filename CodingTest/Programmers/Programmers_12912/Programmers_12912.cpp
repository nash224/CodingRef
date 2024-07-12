// Programmers_12912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


long long solution(int a, int b);

int main()
{
    std::cout << solution(600, -100000);
}

long long solution(int a, int b)
{
	// longlong 쓰기 귀찮아서 에일리어스 타입 선언
	using ReturnType = long long;

	// 전달받은 인자가 음수 양수로 존재하게 되면 상쇄되는 부분이 존재한다.
	// 그 상쇄되는 부분은 제외하고 연산한다. 
	// 예를 들어, -5와 10을 전달 받았으면 -5~5는 상쇄되는 부분이기 때문에 덧셈 연산에서 제외하고
	// 6~10까지만 덧셈 연산을 진행한다.
	ReturnType answer = 0;

	ReturnType MIN_VALUE = static_cast<ReturnType>(std::min(a, b));
	ReturnType MAX_VALUE = static_cast<ReturnType>(std::max(a, b));

	// 부호가 서로 다르면 절대값이 큰 값을 가진 녀석의 부호로 캐스팅한다.
	// 이건 함수로 묶어도 좋을것같다.
	if (MIN_VALUE * MAX_VALUE < 0)
	{
		if (std::abs(MIN_VALUE) > std::abs(MAX_VALUE))
		{
			MAX_VALUE = MAX_VALUE * static_cast<ReturnType>(-1) - static_cast<ReturnType>(1);
		}
		else
		{
			MIN_VALUE = MIN_VALUE * static_cast<ReturnType>(-1) + static_cast<ReturnType>(1);
		}
	}

	// 같은 부호를 가진 수를 덧셈연산한다.
	// 이러한 연산은 수열로 해결가능 하지만, 난 빡대가리라 그런거 모른다.
	for (ReturnType i = MIN_VALUE; i <= MAX_VALUE; i++)
	{
		answer += i;
	}

	return answer;
}