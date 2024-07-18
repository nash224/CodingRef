// BJ_1182.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int Solution(int _N, int _S, const std::vector<int>& _Arr);
void Recursive_Sum(int _Target, int _Index, int _Total, int& _Count, const std::vector<int>& _Arr);

int main()
{
	int N, S;

	std::cin >> N >> S;

	std::vector<int> Arr(N, 0);

	int Num;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Num;
		Arr[i] = Num;
	}

	int Answer = Solution(N, S, Arr);

	if (0 == S) 
	{
		Answer--;
	}

    std::cout << Answer;
}

int Solution(int _N, int _S, const std::vector<int>& _Arr)
{
	int Answer = 0;
	Recursive_Sum(_S, 0, 0, Answer, _Arr);
	return Answer;
}

void Recursive_Sum(int _Target, int _Index, int _Total, int& _Count, const std::vector<int>& _Arr)
{
	if (_Index == _Arr.size())
	{
		if (_Total == _Target)
		{
			_Count++;
		}

		return;
	}

	Recursive_Sum(_Target, _Index + 1, _Total, _Count, _Arr);

	_Total += _Arr[_Index];

	Recursive_Sum(_Target, _Index + 1, _Total, _Count, _Arr);
}