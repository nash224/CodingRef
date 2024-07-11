// BJ_15649.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

void Backtrack(int _N, int _M, int _Depth, int _Idx, std::vector<int>& _Path, std::vector<bool>& _Check, std::vector<std::vector<int>>& _Result) 
{
	if (_Depth == _M) 
	{
		_Result.push_back(_Path);
		return;
	}

	for (int i = _Idx; i < _N; ++i)
	{
		if (false == _Check[i]) 
		{
			_Check[i] = true;
			_Path.push_back(i + 1);
			Backtrack(_N, _M, _Depth + 1, _Idx + 1, _Path, _Check, _Result);
			_Path.pop_back();
			_Check[i] = false;
		}
	}
}

int main() 
{
	int N , M;
	std::cin >> N >> M;

	std::vector<bool> Check(N, false);
	std::vector<int> Path;
	std::vector<std::vector<int>> Result;
	Backtrack(N, M, 0, 0, Path, Check, Result);
	for (const std::vector<int>& Vec : Result)
	{
		for (int Num : Vec)
		{
			std::cout << Num << " ";
		}
		std::cout << '\n';
	}
	return 0;
}