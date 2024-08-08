// Programmers_72410.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

class ID_Interface
{
public:
	std::string Task1(const std::string& _Name);
	std::string Task2(const std::string& _Name);
	std::string Task3(const std::string& _Name);
	std::string Task4(const std::string& _Name);
	std::string Task5(const std::string& _Name);
	std::string Task6(const std::string& _Name);
	std::string Task7(const std::string& _Name);

private:


};

std::string solution(std::string new_id) 
{
	std::string answer = "";

	ID_Interface NewInterface;

	answer = NewInterface.Task1(new_id);
	answer = NewInterface.Task2(answer);
	answer = NewInterface.Task3(answer);
	answer = NewInterface.Task4(answer);
	answer = NewInterface.Task5(answer);
	answer = NewInterface.Task6(answer);
	answer = NewInterface.Task7(answer);

	return answer;
}

int main()
{
	solution("z-+.^.");
    std::cout << "Hello World!\n";
}


std::string ID_Interface::Task1(const std::string& _Name)
{
	std::string Result;

	const int Gap = 'a' - 'A';

	for (int i = 0; i < static_cast<int>(_Name.size()); i++)
	{
		char c = _Name[i];
		if ('A' <= c && c <= 'Z')
		{
			c = c + Gap;
		}

		Result.push_back(c);
	}

	return Result;
}

bool IsValid(char _c)
{
	bool bValidCheck = false;
	if ('a' <= _c && _c <= 'z')
	{
		bValidCheck = true;
	}
	if ('0' <= _c && _c <= '9')
	{
		bValidCheck = true;
	}
	if ('A' <= _c && _c <= 'Z')
	{
		bValidCheck = true;
	}
	if ((_c == '.')
		|| (_c == '-')
		|| (_c == '_'))
	{
		bValidCheck = true;
	}

	return bValidCheck;
}

std::string ID_Interface::Task2(const std::string& _Name)
{
	std::string Result;
	for (int i = 0; i < static_cast<int>(_Name.size()); i++)
	{
		char c = _Name[i];
		if (false == IsValid(c))
		{
			continue;
		}

		Result.push_back(c);
	}

	return Result;
}

std::string ID_Interface::Task3(const std::string& _Name)
{
	std::string Result;

	int DotCount = 0;
	for (int i = 0; i < static_cast<int>(_Name.size()); i++)
	{
		char c = _Name[i];
		if ('.' == c)
		{
			++DotCount;
			if (2 <= DotCount)
			{
				continue;
			}
		}
		else
		{
			DotCount = 0;
		}

		Result.push_back(c);
	}

	return Result;
}

std::string ID_Interface::Task4(const std::string& _Name)
{
	std::string Result;

	if (true == _Name.empty())
	{
		return Result;
	}

	bool FrontCheck = '.' == _Name.front();
	bool BackCheck = '.' == _Name.back();

	const size_t Offset = FrontCheck ? 1 : 0;
	const size_t SIZE = _Name.size();

	const size_t Count = SIZE - Offset - (BackCheck ? 1 : 0);

	Result = _Name.substr(Offset, Count);

	return Result;
}

std::string ID_Interface::Task5(const std::string& _Name)
{
	std::string Result;

	if (_Name.empty())
	{
		Result.push_back('a');
	}
	else
	{
		return _Name;
	}

	return Result;
}

std::string ID_Interface::Task6(const std::string& _Name)
{
	std::string Result;

	const int MAX_LENGH = 15;

	if (MAX_LENGH < static_cast<int>(_Name.size()))
	{
		Result = _Name.substr(0, MAX_LENGH);
	}
	else
	{
		Result = _Name;
	}

	Result = Task4(Result);

	return Result;
}

std::string ID_Interface::Task7(const std::string& _Name)
{
	std::string Result;

	Result = _Name.substr(0, _Name.size());

	while (Result.size() <= 2)
	{
		const char c = _Name.back();
		Result.push_back(c);
	}

	return Result;
}
