// Programmers_155651.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

struct FTime
{
public:
	static int StringToInt(const std::string& _Str)
	{
		return std::stoi(_Str.substr(0, 2)) * 60 + std::stoi(_Str.substr(3, 2));
	}

public:
	FTime() {}

	explicit FTime(const std::string& _Str)
	{
		Str = _Str;
		Time = StringToInt(Str);
	}

	std::string Str;
	int Time = 0;
};

/*  */
int UpdateRoom(std::list<FTime>* _pBookList, const FTime& _CurTime)
{
	std::list<FTime>& List = (*_pBookList);
	List.remove_if([&_CurTime](FTime& _Time)
		{
			return _Time.Time + 10 <= _CurTime.Time;
		});

	return static_cast<int>(List.size());
}

int solution(std::vector<std::vector<std::string>> book_time) 
{
	// 귀찮아서 타입 재정의
	// VVV 너무 길다.
	using BookTime = std::vector<std::string>;

	int answer = 0;
	// 방 현황 업데이트를 위한 컨테이너
	std::list<FTime> BookList;

	// 대실 시작 시간을 기준으로 정렬
	std::sort(book_time.begin(), book_time.end(), [](const BookTime& _Left, const BookTime& _Right)
		{
			return _Left.at(0) < _Right.at(0);
		});

	// 예약 종료시간을 BookList에 넣고 
	// 빈 방이 존재하면 BookList에서 제거한다.
	for (const BookTime& MSG : book_time)
	{
		const FTime StartTime = FTime(MSG.at(0));
		const FTime EndTime = FTime(MSG.at(1));

		BookList.push_back(EndTime);
		const int RoomCount = UpdateRoom(&BookList, StartTime);
		answer = std::max(answer, RoomCount);
	}

	return answer;
}

int main()
{
	solution(
		{
			{ "15:00", "17:00" },
			{ "16:40", "18:20" },
			{ "14:20", "15:20" },
			{ "14:10", "19:20" },
			{ "18:20", "21:20" }
		});
    std::cout << "Hello World!\n";
}
