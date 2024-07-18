// Programmers_154540.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> maps);

int main()
{
	solution({ "X591X","X1X5X","X231X", "1XXX1" });
	int a = 0;
}

class Map
{
public:
	Map(std::vector<std::string>&& maps)
	{
		m_iHeight = static_cast<int>(maps.size());
		m_iWidth = static_cast<int>(maps[0].size());
		m_Maps = maps;
	}

	int Search(int _X, int _Y)
	{
		int ReturnValue = 0;
		ReturnValue += Get(_X, _Y);
		Recursive_Search(ReturnValue, _X, _Y);
		return ReturnValue;
	}

	bool IsEmpty(int _X, int _Y)
	{
		if (_X < 0 || m_iWidth <= _X)
		{
			return true;
		}

		if (_Y < 0 || m_iHeight <= _Y)
		{
			return true;
		}

		if ('X' == m_Maps[_Y][_X])
		{
			return true;
		}

		return false;
	}

private:
	int Index(int _X, int _Y) const
	{
		return _Y * m_iWidth + _X;
	}

	void Recursive_Search(int& _Result, int _X, int _Y)
	{
		if (false == IsEmpty(_X - 1, _Y))
		{
			_Result += Get(_X - 1, _Y);
			Recursive_Search(_Result, _X - 1, _Y);
		}
		if (false == IsEmpty(_X + 1, _Y))
		{
			_Result += Get(_X + 1, _Y);
			Recursive_Search(_Result, _X + 1, _Y);
		}
		if (false == IsEmpty(_X, _Y - 1))
		{
			_Result += Get(_X, _Y - 1);
			Recursive_Search(_Result, _X, _Y - 1);
		}
		if (false == IsEmpty(_X, _Y + 1))
		{
			_Result += Get(_X, _Y + 1);
			Recursive_Search(_Result, _X, _Y + 1);
		}
	}

	int Get(int _X, int _Y)
	{
		const int ReturnValue = static_cast<int>(m_Maps[_Y][_X] - '0');
		m_Maps[_Y][_X] = 'X';
		return ReturnValue;
	}

private:
	std::vector<std::string> m_Maps;
	int m_iWidth = 0;
	int m_iHeight = 0;

};

std::vector<int> solution(std::vector<std::string> maps)
{
	std::vector<int> answer;

	const int HEIGHT = static_cast<int>(maps.size());
	const int WIDTH = static_cast<int>(maps[0].size());

	Map NewMap(std::move(maps));

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (false == NewMap.IsEmpty(x, y))
			{
				const int DAY_COUNT = NewMap.Search(x, y);
				answer.push_back(DAY_COUNT);
			}
		}
	}

	if (true == answer.empty())
	{
		answer.push_back(-1);
	}
	else
	{
		std::sort(answer.begin(), answer.end());
	}

	return answer;
}