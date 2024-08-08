// Programmers_64061.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Crain
{
public:
	Crain(int _Width, int _height)
		: Width(_Width), Height(_height)
	{

	}

public:
	void Pick(int _PickLine, std::vector<std::vector<int>>* pboard)
	{
		const int LINE_NUMBER = _PickLine - 1;
		if (nullptr == pboard)
		{
			return;
		}

		std::vector<std::vector<int>>& Board = (*pboard);
		for (int y = 0; y < Height; y++)
		{
			const int Num = Board[y][LINE_NUMBER];
			if (0 != Num)
			{
				Board[y][LINE_NUMBER] = 0;
				PipeUpdate(Num);
				break;
			}
		}
	}

	inline int Get() const { return mSameCount; };

private:
	void PipeUpdate(int _PickNum)
	{
		if (false == mPipe.empty() && _PickNum == mPipe.top())
		{
			mPipe.pop();
			mSameCount += 2;
			return;
		}

		mPipe.push(_PickNum);
	}

private:
	const int Width;
	const int Height;

	std::stack<int> mPipe;
	int mSameCount = 0;

};

int solution(std::vector<std::vector<int>> board, std::vector<int> moves) 
{
	int answer = 0;

	const int WIDTH = static_cast<int>(board.size());
	const int HEIGHT = static_cast<int>(board[0].size());

	Crain NewCrain = Crain(WIDTH, HEIGHT);

	for (int Line : moves)
	{
		NewCrain.Pick(Line, &board);
	}

	answer = NewCrain.Get();

	return answer;
}

int main()
{
	solution({ { 0,0,0,0,0 }, { 0,0,1,0,3 }, { 0,2,5,0,1 }, { 4,2,4,4,2 }, { 3,5,1,3,1 } }, { 1,5,3,5,1,2,1,4 });
    std::cout << "Hello World!\n";
}
