// Programmers_340211.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>
#include <list>

struct Int2
{
	Int2(int _X = 0, int _Y = 0)
		: X(_X)
		, Y(_Y)
	{

	}

	int X;
	int Y;
};

class CRobot
{
	static constexpr int NONE_PATH = 0;

public:
	static CRobot MakeRobot(const std::vector<int>& _Route, const std::map<int, Int2>& _Points)
	{
		CRobot NewRobot;

		if (true == _Route.empty() || true == _Points.empty())
		{
			// ERROR
			return NewRobot;
		}

		const int StartIndex = _Route.at(0);
		NewRobot.mPos = _Points.at(StartIndex);
		NewRobot.mRoute = _Route;
		NewRobot.mCurPath = 0;

		return NewRobot;
	}

	void Update()
	{

	}

private:
	Int2 mPos;
	int mCurPath = NONE_PATH;
	std::vector<int> mRoute;

};

int solution(std::vector<std::vector<int>> points, std::vector<std::vector<int>> routes)
{
	int answer = 0;

	int Number = 0;
	std::map<int, Int2> Points;
	std::list<CRobot> mRobotList;

	for (const std::vector<int>& Point : points)
	{
		++Number;
		const Int2 Coord = Int2(Point.at(1) - 1, Point.at(0) - 1);
		Points.insert(std::make_pair(Number, Coord));
	}

	for (const std::vector<int>& Route : routes)
	{
		CRobot Robot = CRobot::MakeRobot(Route, Points);
		mRobotList.push_back(Robot);
	}

	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}