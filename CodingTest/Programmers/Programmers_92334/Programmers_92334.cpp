// Programmers_92334.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

std::pair<std::string, std::string> Split(const std::string& _Src)
{
	const size_t FIND_OFFSET = _Src.find(' ');
	const std::string String1 = _Src.substr(0, FIND_OFFSET);
	const std::string String2 = _Src.substr(FIND_OFFSET + 1, _Src.size());
	return { String1 , String2 };
}

class PlayerInfo
{
public:
	PlayerInfo(const std::string& _Name,int _Number)
		: Name(_Name)
		, Number(_Number)
	{

	}

	~PlayerInfo()
	{

	}

public:
	void Report(PlayerInfo* _pInfo, int _BanCount)
	{
		if (nullptr == _pInfo)
		{
			return;
		}

		std::set<int>::const_iterator FindIter = mReportList.find(_pInfo->Number);
		if (mReportList.end() != FindIter)
		{
			return;
		}

		mReportList.insert(_pInfo->Number);
		mReportPlayerList.insert(_pInfo);
		_pInfo->mReportedCount += 1;
		if (_BanCount <= _pInfo->mReportedCount)
		{
			_pInfo->bReport = true;
		}
	}

	int GetBannedCount() const
	{
		int Result = 0;

		for (const PlayerInfo* pInfo : mReportPlayerList)
		{
			if (true == pInfo->bReport)
			{
				++Result;
			}
		}

		return Result;
	}

	int GetNumber() const { return Number; }

private:
	std::string Name;
	const int Number;
	std::set<int> mReportList;
	std::set<PlayerInfo*> mReportPlayerList;
	int mReportedCount = 0;
	bool bReport = false;

};

std::vector<int> solution(std::vector<std::string> id_list, std::vector<std::string> report, int k) 
{
	std::vector<int> answer(id_list.size(), 0);

	const int LIST_SIZE = static_cast<int>(id_list.size());

	std::unordered_map<std::string, PlayerInfo> Dictionary;

	for (int i = 0; i < LIST_SIZE; i++)
	{
		PlayerInfo NewInfo = PlayerInfo(id_list[i], i);
		Dictionary.insert(std::make_pair(id_list[i], NewInfo));
	}

	for (const std::string& MSG : report)
	{
		const std::pair<std::string, std::string> pair = Split(MSG);
		const std::string Reporter = pair.first;
		const std::string Reported = pair.second;

		auto Reporter_FindIter = Dictionary.find(Reporter);
		if (Dictionary.end() == Reporter_FindIter)
		{
			return std::vector<int>();
		}

		auto Reported_FindIter = Dictionary.find(Reported);
		if (Dictionary.end() == Reported_FindIter)
		{
			return std::vector<int>();
		}

		PlayerInfo& ReporterInfo = Reporter_FindIter->second;
		PlayerInfo& ReportedInfo = Reported_FindIter->second;
		ReporterInfo.Report(&ReportedInfo, k);
	}

	for (const auto& pair  : Dictionary)
	{
		const int BannedCount = pair.second.GetBannedCount();
		const int NUMBER = pair.second.GetNumber();
		answer[NUMBER] = BannedCount;
	}

	return answer;
}

int main()
{
	solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
	Split({ "muzi frodo" });
    std::cout << "Hello World!\n";
}