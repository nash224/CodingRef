// Programmers_340212.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using TimeType = long long;

TimeType GetSolveTime(int _Level, int _Diff, TimeType _Cur, TimeType _Prev = 0)
{
	int Loop = _Level < _Diff ? (_Diff - _Level) : 1;
	return (_Prev + _Cur) * static_cast<TimeType>(Loop) + _Cur;
}

int solution(std::vector<int> diffs, std::vector<int> times, long long limit) 
{
	int answer = 0;

	const int SIZE = static_cast<int>(diffs.size());

	int Level = 1;
	int Lower = 1;
	int High = 0;
	while (true)
	{
		TimeType Total_Time = 0;
		TimeType Prev_Time = 0;
		TimeType Cur_Time = 0;

		for (int i = 0; i < SIZE; i++)
		{
			Cur_Time = times[i];

			Total_Time += GetSolveTime(Level, diffs[i], Cur_Time, Prev_Time);

			Prev_Time = Cur_Time;
		}

		Level *= 2;
	}


	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
