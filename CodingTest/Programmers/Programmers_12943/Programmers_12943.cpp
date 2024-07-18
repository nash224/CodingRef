// Programmers_12943.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using DataType = size_t;
int solution(DataType  num);


int main()
{
	std::cout << solution(626331);
}

void Print(DataType  _Num)
{
	std::cout << _Num << '\n';
}

int solution(DataType  num)
{
	int answer = 0;

	// 람다함수 
	// [개시자] (인자)->{반환타입} {함수 몸체}로 구성
	// 런타임 시에 이름은 없지만, 클로져라는 객체가 컴파일러로부터 생성되고 함수 객체(Functor)처럼 행동함
	auto EvenMethod = [&num](){num /= 2; Print(num); };
	auto OddMethod = [&num]() { num = num * 3 + 1; Print(num); };

	if (num == 1)
	{
		answer = 0;
	}
	else
	{
		while (true)
		{
			++answer;

			if (num % 2)
			{
				OddMethod();
			}
			else
			{
				EvenMethod();
			}

			if (500 <= answer)
			{
				answer = -1;
				break;
			}
			else if (1 == num)
			{
				break;
			}
		}
	}

	return answer;
}