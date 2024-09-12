// Programmers_340198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

#define EMPTY_SPACE "-1"

struct Int2
{
	static Int2 ZERO;

public:
	Int2(int _X = 0, int _Y = 0)
		: X(_X)
		, Y(_Y)
	{

	}

	int X;
	int Y;

	Int2 operator+(const Int2& _Other) const
	{
		return Int2(X + _Other.X, Y + _Other.Y);
	}

	Int2 operator-(const Int2& _Other) const
	{
		return Int2(X - _Other.X, Y - _Other.Y);
	}
};

Int2 Int2::ZERO;

struct FBox
{
	FBox() {}
	FBox(const Int2& _Pos, const Int2& _Size)
		: Pos(_Pos)
		, Size(_Size)
	{

	}

	Int2 Pos = Int2::ZERO;
	Int2 Size = Int2::ZERO;

	bool Colllsion(const FBox& _Other) const
	{
		const Int2 LT = Pos;
		const Int2 RB =  Pos + Size - Int2(1,1);
		const Int2 OTHER_LT = _Other.Pos;
		const Int2 OTHER_RB = _Other.Pos + _Other.Size - Int2(1, 1);

		if ((LT.X <= OTHER_RB.X)
			&& (OTHER_LT.X <= RB.X)
			&& (LT.Y <= OTHER_RB.Y)
			&& (OTHER_LT.Y <= RB.Y))
		{
			return true;
		}

		return false;
	}
};

FBox SearchAndMakeBox(const std::vector<std::vector<std::string>>& park, const Int2& _Pos)
{
	FBox Result;

	const int HEIGHT = static_cast<int>(park.size());
	const int WIDTH = static_cast<int>(park[0].size());

	Int2 Size;

	for (int y = _Pos.Y; y < HEIGHT; y++)
	{
		if (EMPTY_SPACE == park[y][_Pos.X])
		{
			Size.Y = y - _Pos.Y;
			break;
		}
	}

	for (int x = _Pos.X; x < WIDTH; x++)
	{
		if (EMPTY_SPACE == park[_Pos.Y][x])
		{
			Size.X = x - _Pos.X;
			break;
		}
	}

	if (0 == Size.Y)
	{
		Size.Y = HEIGHT - _Pos.Y;
	}

	if (0 == Size.X)
	{
		Size.X = WIDTH - _Pos.X;
	}

	Result.Pos = _Pos;
	Result.Size = Size;

	return Result;
}

std::vector<FBox> Initialize(const std::vector<std::vector<std::string>>& park)
{
	std::vector<FBox> Result;
	std::set<std::string> Contains;

	if (true == park.empty())
	{
		return Result;
	}

	const int HEIGHT = static_cast<int>(park.size());
	const int WIDTH = static_cast<int>(park[0].size());

	std::string Buffer = EMPTY_SPACE;
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			std::string Elem = park[y][x];
			if (EMPTY_SPACE == Elem)
			{
				Buffer = EMPTY_SPACE;
			}
			else if (Buffer == Elem)
			{
				continue;
			}
			else
			{
				if (Contains.end() == Contains.find(Elem))
				{
					Result.push_back(SearchAndMakeBox(park, Int2(x, y)));
					Contains.insert(Elem);
				}
			}
		}
	}

	return Result;
}

int solution(std::vector<int> mats, std::vector<std::vector<std::string>> park) 
{
	int answer = 0;
	if (true == mats.empty())
	{
		return -1;
	}

	std::sort(mats.begin(), mats.end());
	const int MAT_SIZE = static_cast<int>(mats.size());
	int CurIndex = 0;
	int CurMat = mats.at(0);
	answer = CurMat;

	std::vector<FBox> Boxes = Initialize(park);

	const int HEIGHT = static_cast<int>(park.size());
	const int WIDTH = static_cast<int>(park[0].size());

	bool bEnd = false;

	std::string Elem;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (true == bEnd)
			{
				break;
			}

			Elem = park[y][x];
			if (EMPTY_SPACE == Elem)
			{
				while (true)
				{
					const Int2 RightBottom = Int2(x + CurMat - 1, y + CurMat - 1);
					if (WIDTH <= RightBottom.X)
					{
						break;
					}
					if (HEIGHT <= RightBottom.Y)
					{
						bEnd = true;
						break;
					}

					bool bCollision = false;
					for (const FBox& Box : Boxes)
					{
						if (true == Box.Colllsion(FBox({ x,y }, { CurMat, CurMat })))
						{
							bCollision = true;
							break;
						}
					}

					if (true == bCollision)
					{
						break;
					}

					++CurIndex;
					if (MAT_SIZE <= CurIndex)
					{
						bEnd = true;
						break;
					}

					answer = CurMat;
					CurMat = mats.at(CurIndex);
				}
			}
		}
	}

	return answer;
}

int main()
{
	solution({ 5,3,2 },
		{
			{"A", "A", "-1", "B", "B", "B", "B", "-1"},
			{"A", "A", "-1", "B", "B", "B", "B", "-1"},
			{"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
			{"D", "D", "-1", "-1", "-1", "-1", "E", "-1"},
			{"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},
			{"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}
		});
    std::cout << "Hello World!\n";
}
