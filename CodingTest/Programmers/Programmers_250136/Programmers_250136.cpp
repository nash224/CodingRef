// Programmers_250136.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

class Int2
{
public:
	Int2(int _X = 0, int _Y = 0)
		: X(_X), Y(_Y)
	{
	}

public:
	Int2& operator=(const Int2& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
		return *this;
	}

	union
	{
		std::pair<int, int> Pair;
		struct 
		{
			int X;
			int Y;
		};
	};
};

class Fuel
{
public:
	Fuel()
	{
	}

	void operator++()
	{
		++mSize;
	}

	int GetSize() const { return mSize; }

private:
	int mSize = 0;

};

// 기름맵을 가짐
// 우선 모든 기름을 순회하면서 찾고
// 연결된 기름을 Fuel에 보관 후, Vector로 관리
// 찾은 기름은 맵에 표시하고 다시 찾지 않음	
//		-> 비용이 발생하기 때문
//		-> 만약 기름을 찾았을때, Checkmap에서 이미 발견된 기름이면 검색하지 않음
// Check가 완료된 기름맵에 시추를 하면 중복된 기름을 찾을 경우, 확인을 어떻게 하지?
//		std::pair<Fuel, bool> 형태로 보관하는건 어떨까?
//		맵버로 보관할 필요는 없어보임, 즉 지역변수사용

class CFuelMap
{
public:
	CFuelMap(int _Width, int _Height)
		:WIDTH(_Width), HEIGHT(_Height)
	{
		const int SIZE = WIDTH* HEIGHT;
		m_CheckMap = new bool[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			m_CheckMap[i] = false;
		}

		FuelMap.resize(HEIGHT);
		for (int i = 0; i < HEIGHT; i++)
		{
			FuelMap[i].resize(WIDTH);
		}
	}

	~CFuelMap()
	{
		if (nullptr != m_CheckMap)
		{
			delete[] m_CheckMap;
			m_CheckMap = nullptr;
		}
	}

public:
	bool IsSearch(int _Y, int _X)
	{
		if (nullptr == m_CheckMap)
		{
			return false;
		}

		return m_CheckMap[Index(_Y, _X)];
	}

	void SearchMap(const std::vector<std::vector<int>>& pland)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				const bool ISFUEL = (1 == pland[y][x]);
				const bool ISCHECK = m_CheckMap[Index(y, x)];
				if (true == ISFUEL && false == ISCHECK)
				{
					Fuels.emplace_back();
					Fuel& NewFuel = Fuels.back();
					Recursive_Search(&NewFuel, pland, y, x);
				}

				m_CheckMap[Index(y, x)] = true;
			}
		}

		int a = 0;
	}

	int GetFuelAmount(int _X)
	{
		int iTotal = 0;

		std::set<Fuel*> FindList;
		for (int y = 0; y < HEIGHT; y++)
		{
			if (nullptr != FuelMap[y][_X])
			{
				FindList.insert(FuelMap[y][_X]);
			}
		}

		for (Fuel* pFuel : FindList)
		{
			iTotal += pFuel->GetSize();
		}

		return iTotal;
	}

private:
	int Index(int _Y, int _X) const
	{
		if (true == OutBoundary(_Y, _X))
		{
			return 0;
		}

		const int Idx = WIDTH* _Y + _X;
		return WIDTH * _Y + _X;
	}

	bool OutBoundary(int _Y, int _X) const
	{
		if (_Y < 0 || HEIGHT <= _Y)
		{
			return true;
		}
		if (_X < 0 || WIDTH <= _X)
		{
			return true;
		}

		return false;
	}

	void Recursive_Search(Fuel* _pFuel, const std::vector<std::vector<int>>& pland, int _Y, int _X)
	{
		if (true == OutBoundary(_Y, _X) || true == m_CheckMap[Index(_Y, _X)])
		{
			return;
		}

		m_CheckMap[Index(_Y, _X)] = true;
		if (1 == pland[_Y][_X])
		{
			FuelMap[_Y][_X] = _pFuel;
			++(*_pFuel);
			Recursive_Search(_pFuel, pland, _Y + 1, _X); // 상
			Recursive_Search(_pFuel, pland, _Y - 1, _X); // 하
			Recursive_Search(_pFuel, pland, _Y, _X - 1); // 좌
			Recursive_Search(_pFuel, pland, _Y, _X + 1); // 우
		}
	}

private:
	bool* m_CheckMap = nullptr;
	std::vector<std::vector<Fuel*>> FuelMap;
	std::list<Fuel> Fuels;
	const int WIDTH;
	const int HEIGHT;

};

int solution(std::vector<std::vector<int>> land);

int main()
{
	solution({
		{ 1, 0, 1, 0, 1, 1 },
		{1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0},
		{1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1} });
}

int solution(std::vector<std::vector<int>> land)
{
	int answer = 0;

	const int HEIGHT = static_cast<int>(land.size());
	const int WIDTH = static_cast<int>(land[0].size());

	CFuelMap NewBitMap(WIDTH, HEIGHT);

	NewBitMap.SearchMap(land);

	std::vector<int> Amounts;

	for (int i = 0; i < WIDTH; i++)
	{
		Amounts.push_back(NewBitMap.GetFuelAmount(i));
	}

	for (int Amount : Amounts)
	{
		answer = std::max(Amount, answer);
	}

	return answer;
}