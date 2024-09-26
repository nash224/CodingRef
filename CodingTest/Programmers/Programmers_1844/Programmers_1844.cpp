// Programmers_1844.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <memory>

// maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열
// 0은 벽이 있는 자리, 1은 벽이 없는 자리
// 처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 
// 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.

struct Int2
{
	static Int2 ZERO;

	Int2(int _X = 0, int _Y = 0)
		: X(_X)
		, Y(_Y)
	{

	}

	union
	{
		struct
		{
			int X;
			int Y;
		};

		long long ID;
	};

	Int2 operator+(const Int2& _Other) const
	{
		return Int2(X + _Other.X, Y + _Other.Y);
	}

	bool operator==(const Int2& _Other) const
	{
		return (_Other.X == X) && (_Other.Y == Y);
	}
};

Int2 Int2::ZERO;

class CBoard
{
public:
	static constexpr int PATH = 0;
	static constexpr int WALL = 1;
	static constexpr int NOT_FOUND = -1;

public:
	CBoard(const std::vector<std::vector<int>>& maps)
		: mMap(maps)
	{
		if (true == mMap.empty())
		{
			return;
		}

		mHeight = static_cast<int>(mMap.size());
		mWidth = static_cast<int>(mMap[0].size());
	}

	bool RangeOut(const Int2& _Pos) const
	{
		if (_Pos.X < 0)
		{
			return true;
		}
		if (_Pos.Y < 0)
		{
			return true;
		}
		if (mHeight <= _Pos.Y)
		{
			return true;
		}
		if (mWidth <= _Pos.X)
		{
			return true;
		}

		return false;
	}

	bool IsBlock(const Int2& _Pos) const
	{
		return RangeOut(_Pos) || (WALL == mMap[_Pos.Y][_Pos.X]);
	}

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

private:
	const std::vector<std::vector<int>>& mMap;
	int mWidth = 0;
	int mHeight = 0;

};

int solution(std::vector<std::vector<int>> maps)
{
	int answer = 0;

	CBoard NewBoard = CBoard(maps);

	const Int2 StartPos = Int2(0, 0);
	const Int2 TargetPos = Int2(NewBoard.GetWidth(), NewBoard.GetHeight());

	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
