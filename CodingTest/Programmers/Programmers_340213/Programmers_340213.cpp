// Programmers_340213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

// 홍대병 걸린 풀이법

namespace video_command
{
	constexpr const char* NEXT = "next";
	constexpr const char* PREV = "prev";
	constexpr const char* PER_TIME = "00:10";
}

struct FTime
{
	static FTime Result;

	FTime() {}

	explicit FTime(const std::string& _Str, bool _bNegative = false)
	{
		Str = _Str;
		Time = SToI(_Str);
		bNegative = _bNegative;
	}

	std::string Str;
	int Time = 0;
	bool bNegative = false;

	void Add(const FTime& _Time)
	{
		const int N = _Time.Time * (_Time.bNegative ? -1 : 1);
		Time += N;
		if (true == IsBelowZero())
		{
			Time = 0;
		}
		Str = IToS(Time);
	}

	static int SToI(const std::string& _Str)
	{
		const int Min = std::stoi(_Str.substr(0, 2));
		const int Sec = std::stoi(_Str.substr(3, 2));
		return Min * 60 + Sec;
	}

	static std::string& IToS(int _Time)
	{
		static std::string Result;
		Result.clear();

		const int Min = _Time / 60;
		const int Sec = _Time % 60;

		Result += To00String(std::to_string(Min));
		Result += ':';
		Result += To00String(std::to_string(Sec));

		return Result;
	}

	static std::string& To00String(const std::string& _Str)
	{
		static std::string Result;
		Result.clear();

		if (1 == _Str.size())
		{
			Result += '0';
		}

		Result += _Str;

		return Result;
	}


	std::string GetStringTime() const { return Str; }

private:
	bool IsBelowZero() const
	{
		return Time < 0;
	}

};

FTime FTime::Result;

struct FVideo
{
	FVideo(const FTime& _Length, const FTime& _OPTime, const FTime& _EDTime)
		: Length(_Length)
		, OP_STime(_OPTime)
		, OP_ETime(_EDTime)
	{

	}

	bool IsOP(const FTime& _Time) const
	{
		return OP_STime.Time <= _Time.Time && _Time.Time < OP_ETime.Time;
	}

	bool IsEnd(const FTime& _Time) const
	{
		return Length.Time <= _Time.Time;
	}

	FTime Length;
	FTime OP_STime;
	FTime OP_ETime;

};

class CPlayer
{
public:
	CPlayer()
	{

	}


public:
	inline void SetVideo(FVideo* _Object, const FTime& _CurTime) 
	{
		if (nullptr == _Object)
		{
			return;
		}

		mCurTime = _CurTime;
		mVideo = _Object; 
		if (true == mVideo->IsOP(mCurTime))
		{
			mCurTime = mVideo->OP_ETime;
		}
	}

	void Command(const std::string& _MSG)
	{
		if (nullptr == mVideo)
		{
			return;
		}

		const FTime MoveTime = ConvertTime(_MSG);
		mCurTime.Add(MoveTime);

		if (true == mVideo->IsEnd(mCurTime))
		{
			mCurTime = mVideo->Length;
		}

		if (true == mVideo->IsOP(mCurTime))
		{
			mCurTime = mVideo->OP_ETime;
		}
	}

	const FTime& GetTime() const { return mCurTime; }

private:
	FTime& ConvertTime(const std::string& _MSG)
	{
		FTime::Result;

		if (video_command::PREV == _MSG)
		{
			FTime::Result = FTime(video_command::PER_TIME, true);
		}
		else if (video_command::NEXT == _MSG)
		{
			FTime::Result = FTime(video_command::PER_TIME);
		}
		
		return FTime::Result;
	}

private:
	FVideo* mVideo = nullptr;
	FTime mCurTime;

};

std::string solution(std::string video_len, std::string pos, std::string op_start, std::string op_end, std::vector<std::string> commands) 
{
	CPlayer NewPlayer;
	FVideo NewObject = FVideo(FTime(video_len), FTime(op_start), FTime(op_end));

	NewPlayer.SetVideo(&NewObject, FTime(pos));

	for (const std::string& Command : commands)
	{
		NewPlayer.Command(Command);
	}

	return NewPlayer.GetTime().GetStringTime();
}

int main()
{
	solution("34:33", "13:00", "00:55", "02:55", { "next", "prev" });
    std::cout << "Hello World!\n";
}
