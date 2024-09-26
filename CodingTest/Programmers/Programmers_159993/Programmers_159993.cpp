// Programmers_159993.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Int2
{
	static const Int2 ZERO;
	static const Int2 Error;

	Int2(int _X = 0, int _Y = 0)
		: X(_X)
		, Y(_Y)
	{

	}

	int X = 0;
	int Y = 0;

	Int2 operator+(const Int2& _Other) const
	{
		return Int2(X + _Other.X, Y + _Other.Y);
	}

	bool operator==(const Int2& _Other) const
	{
		return (X == _Other.X) && (Y == _Other.Y);
	}
};

const Int2 Int2::ZERO = {0,0};
const Int2 Int2::Error = (-1, -1);

class CBoard
{
public:
	CBoard(const std::vector<std::string>& _Map)
		: Map(_Map)
	{
		if (true == _Map.empty())
		{
			// Error
			return;
		}

		Width = static_cast<int>(_Map[0].size());
		Height = static_cast<int>(_Map.size());
	}

public:
	int BFS(Int2* Pos, const Int2& _Target) const
	{
		std::queue<std::pair<Int2, int>> Queue;
		std::vector<std::vector<bool>> Visitd;
		Visitd.resize(Height);
		for (int i = 0; i < Height; i++)
		{
			Visitd[i].resize(Width);
		}

		Queue.push(std::make_pair(*Pos, 0));

		while (false == Queue.empty())
		{
			const Int2 CurPos = Queue.front().first;
			const int Cost = Queue.front().second;
			Queue.pop();

			static const Int2 Dirs[4] =
			{
				{-1,0},
				{1,0},
				{0,-1},
				{0,1}
			};

			Int2 CheckPos;
			for (const Int2& Dir : Dirs)
			{
				CheckPos = CurPos + Dir;

				if (true == IsBlock(CheckPos) || true == Visitd[CheckPos.Y][CheckPos.X])
				{
					continue;
				}
				else if (_Target == CheckPos)
				{
					(*Pos) = _Target;
					return Cost + 1;
				}

				Visitd[CheckPos.Y][CheckPos.X] = true;
				Queue.push(std::make_pair(CheckPos, Cost + 1));
			}
		}

		return -1;
	}

	Int2 Find(char _Char) const
	{
		for (int y = 0; y < Height; y++)
		{
			for (int x = 0; x < Width; x++)
			{
				if (_Char == Map[y][x])
				{
					return Int2(x, y);
				}
			}
		}

		return Int2::Error;
	}

private:

private:
	bool IsBlock(const Int2& _Index) const
	{
		if (_Index.X < 0 || Width <= _Index.X)
		{
			return true;
		}

		if (_Index.Y < 0 || Height <= _Index.Y)
		{
			return true;
		}

		if (WALL == Map[_Index.Y][_Index.X])
		{
			return true;
		}

		return false;
	}

private:
	const std::vector<std::string>& Map;
	int Width = 0;
	int Height = 0;

	const char WALL = 'X';

};

int solution(std::vector<std::string> maps)
{
	int answer = 0;

	CBoard Board = CBoard(maps);

	const Int2 Start = Board.Find('S');
	const Int2 Exit = Board.Find('E');
	const Int2 Lever = Board.Find('L');

	Int2 CurPos = Start;

	{
		const int Cost = Board.BFS(&CurPos, Lever);
		if (Cost < 0)
		{
			return -1;
		}

		answer += Cost;
	}

	{
		const int Cost = Board.BFS(&CurPos, Exit);
		if (Cost < 0)
		{
			return -1;
		}

		answer += Cost;
	}

	return answer;
}

int main()
{
	solution({ "SELXX", "XXXXX", "XXXXX", "XXXXX", "XXXXX" });
    std::cout << "Hello World!\n";
}
