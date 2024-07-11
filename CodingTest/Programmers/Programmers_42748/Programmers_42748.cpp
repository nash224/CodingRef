// Programmers_42748.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct FCommandInfo
{
public:
	int i = 0;
	int j = 0;
	int k = 0;
};

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands);

void Initialize(const std::vector<std::vector<int>>& _Rsc, std::vector<FCommandInfo>* _pOut);

int GetSoulution(const std::vector<int>& _array, const FCommandInfo& _Info);

int main()
{
	std::vector<int> Array{ 1, 5, 2, 6, 3, 7, 4 } ;
	std::vector<std::vector<int>> Commands{ {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
	std::vector<int> Answer = solution(Array, Commands);

	for (int i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << ' ';
	}
}

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands)
{
	if (array.size() < 1 && 100 < array.size())
	{
		// assert
		return std::vector<int>();
	}

	for (int Elem : array)
	{
		if (Elem < 1 && 100 < Elem)
		{
			// assert
			return std::vector<int>();
		}
	}

	std::vector<int> answer;
	answer.resize(commands.size());

	std::vector<FCommandInfo> Infos;
	Initialize(commands, &Infos);

	for (int i = 0; i < Infos.size(); i++)
	{
		answer[i] = GetSoulution(array, Infos[i]);
	}

	return answer;
}

void Initialize(const std::vector<std::vector<int>>& _Rsc, std::vector<FCommandInfo>* _pOut)
{
	if (nullptr == _pOut)
	{
		// assert
		return;
	}

	if (_Rsc.size() < 1 && 50 < _Rsc.size())
	{
		// assert
		return;
	}

	std::vector<FCommandInfo>& CommandInfos = (*_pOut);
	CommandInfos.reserve(_Rsc.size());

	for (const std::vector<int>& Command : _Rsc)
	{
		if (3 != Command.size())
		{
			// assert
			return;
		}

		FCommandInfo NewInfo;
		NewInfo.i = Command[0];
		NewInfo.j = Command[1];
		NewInfo.k = Command[2];

		CommandInfos.emplace_back(NewInfo);
	}
}

int GetSoulution(const std::vector<int>& _array, const FCommandInfo& _Info)
{
	const int FROM = _Info.i;
	const int TO = _Info.j;
	const int ORDER = _Info.k;

	std::vector<int> Arr;
	Arr.reserve((TO - FROM + 1));
	for (int i = FROM - 1; i < TO; i++)
	{
		Arr.push_back(_array[i]);
	}

	std::sort(Arr.begin(), Arr.end(), [](int _v1, int _v2)
		{
			return _v1 < _v2;
		});


	return Arr[ORDER - 1];
}