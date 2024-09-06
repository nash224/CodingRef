// Programmers_17681.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

// 암호화된 배열을 이진수로 만들고, 1인 부불을 벽으로 만든다.
// 두 지도 중, 어느 한곳이라도 벽이라면 그 부분을 벽으로 판정한다.

constexpr int BIT_16 = 16;

// 정수를 비트화한다.
std::string& ToBit(int _Num)
{
	static std::string String;

	String = std::bitset<BIT_16>(_Num).to_string();

	return String;
}

// 정수 배열로 특정 지도를 만든다.
std::vector<std::string>& CreateSecretMap(int _n, const std::vector<int>& _Arr)
{
	static std::vector<std::string> Result;
	Result.reserve(_n);
	Result.clear();

	const int ARRAY_SIZE = static_cast<int>(_Arr.size());
	const int MAX_NUMBER = static_cast<int>(std::pow(2, _n)) - 1;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		static std::string String;
		const int Num = _Arr[i];
		String = ToBit(Num);
		String = String.substr(BIT_16 - _n, _n);
		Result.push_back(String);
	}


	return Result;
}

// 두 문자열을 비교하여 벽인 부부분과 공백 부분로 변환하여 반환한다..
std::vector<std::string>& MakeSecretMap(const std::vector<std::string>& _MapA, const std::vector<std::string>& _MapB)
{
	static std::vector<std::string> Result;

	Result = _MapA;

	const int ARRAY_SIZE = static_cast<int>(_MapA.size());

	for (int y = 0; y < ARRAY_SIZE; y++)
	{
		for (int x = 0; x < ARRAY_SIZE; x++)
		{
			const char WallData = '1';
			if (WallData == _MapA[y][x] || WallData == _MapB[y][x])
			{
				Result[y][x] = '#';
			}
			else
			{
				Result[y][x] = ' ';
			}
		}
	}

	return Result;
}

std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2) 
{
	std::vector<std::string> answer;

	const std::vector<std::string> MapA = CreateSecretMap(n, arr1);
	const std::vector<std::string> MapB = CreateSecretMap(n, arr2);
	answer = MakeSecretMap(MapA, MapB);

	return answer;
}



int main()
{
	solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });

    std::cout << "Hello World!\n";
}
