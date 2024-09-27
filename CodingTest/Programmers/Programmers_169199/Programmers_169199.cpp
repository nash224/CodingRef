// Programmers_169199.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Int2
{
public:
	static const Int2 ERROR;

public:
	Int2(int _X = 0, int _Y = 0)
		:X(_X)
		, Y(_Y)
	{

	}

	int X = 0;
	int Y = 0;

	Int2 operator+(const Int2& _Other) const
	{
		return Int2(X + _Other.X, Y + _Other.Y);
	}

	Int2& operator+=(const Int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		return *this;
	}

	bool operator==(const Int2& _Other) const
	{
		return (X == _Other.X) && (Y == _Other.Y);
	}
};

const Int2 Int2::ERROR = Int2(-1, -1);

class CBoard
{
public:
	CBoard(const std::vector<std::string>& _Map)
		: mMap(_Map)
	{
		if (true == _Map.empty())
		{
			return;
		}

		mHeight = static_cast<int>(_Map.size());
		mWidth = static_cast<int>(_Map[0].size());
	}

	/* 맵 리소스에서 특정 문자열의 위치를 반환한다. */
	Int2 Find(char _Char) const
	{
		for (int y = 0; y < mHeight; y++)
		{
			for (int x = 0; x < mWidth; x++)
			{
				if (_Char == mMap[y][x])
				{
					return Int2(x, y);
				}
			}
		}
		return Int2::ERROR;
	}

	/* 너비 탐색을 통해 길찾기를 수행한다 */
	int BFS(const Int2& _Pos, const Int2& _Target) const
	{
		// Queue에 담을 구조체 선언
		struct FInfo
		{
			Int2 Pos;
			int Cost;
		};

		std::queue<FInfo> Pipe;
		std::vector<std::vector<bool>> Visited;
		Visited.resize(mHeight);
		for (int i = 0; i < mHeight; i++)
		{
			Visited[i].resize(mWidth);
		}

		// 시작 점의 위치를 넣어줌
		Pipe.push({_Pos, 0});

		// 파이프가 아무것도 들어있지 않을때까지 반복한다.
		while (false == Pipe.empty())
		{
			const Int2 CurPos = Pipe.front().Pos;
			const int Cost = Pipe.front().Cost;
			Pipe.pop();

			// 4가지 방향 선언
			static const Int2 Dirs[4] =
			{
				{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}
			};

			Int2 CheckPos;
			for (const Int2& Dir : Dirs)
			{
				CheckPos = CurPos;

				// 특정 방향으로 막힐때까지 위치를 갱신한다.
				while (false == IsBlock(CheckPos + Dir))
				{
					CheckPos += Dir;
				}

				// 벽 앞까지 갱신된 위치가 방문했던 좌표라면 건너뛴다.
				if (true == Visited[CheckPos.Y][CheckPos.X])
				{
					continue;
				}
				// 벽 앞까지 갱신된 위치가 방문했던 좌표라면 목표 위치라면 비용을 반환한다.
				else if (_Target == CheckPos)
				{
					return Cost + 1;
				}
				else
				{
					Visited[CheckPos.Y][CheckPos.X] = true;
					Pipe.push({CheckPos, Cost + 1});
				}
			}
		}

		return -1;
	}

	/* Block 처리를 수행한다. */
	bool IsBlock(const Int2& _Pos) const
	{
		if (_Pos.X < 0 || mWidth <= _Pos.X)
		{
			return true;
		}

		if (_Pos.Y < 0 || mHeight <= _Pos.Y)
		{
			return true;
		}

		if (WALL == mMap[_Pos.Y][_Pos.X])
		{
			return true;
		}

		return false;
	}

private:
	const std::vector<std::string>& mMap;
	int mWidth = 0;
	int mHeight = 0;

	const char WALL = 'D';

};

int solution(std::vector<std::string> board)
{
	CBoard NewBoard = CBoard(board);
	const Int2 StartPos = NewBoard.Find('R');
	const Int2 TargetPos = NewBoard.Find('G');

	const int COST = NewBoard.BFS(StartPos, TargetPos);
	return COST < 0 ? -1 : COST;
}

int main()
{
	solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    std::cout << "Hello World!\n";
}
