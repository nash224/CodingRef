// Programmers_169199.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

#define ROCK 'D'
#define GOAL 'G'
#define PLAYER 'P'

class Int2
{
public:
	Int2(int _x =0 , int _y = 0)
		: X(_x), Y(_y)
	{

	}

private:
	int X;
	int Y;

};

class CBoard
{
public:
	std::list<char> FindPath(const std::vector<std::string>& board)
	{
		BFS(board, {}, GetPlayerIndex(board));

		return mPath;
	}

private:
	void BFS(const std::vector<std::string>& _Board, std::list<char> _Path, const Int2& _PlayerPos)
	{

	}

	Int2 GetPlayerIndex(const std::vector<std::string>& _Board)
	{
		const int HEIGHT = static_cast<int>(_Board.size());
		const int WIDTH = static_cast<int>(_Board[0].size());

		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				if (PLAYER == _Board[y][x])
				{
					return Int2(x, y);
				}
			}
		}

		return Int2();
	}

private:
	std::list<char> mPath;
};

int solution(std::vector<std::string> board)
{
	int answer = 0;

	CBoard NewBoard;
	NewBoard.FindPath(board);

	return answer;
}

int main()
{
	solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    std::cout << "Hello World!\n";
}
