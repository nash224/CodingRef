// Programmers_258712.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include "unordered_map"
#include <map>
#include <sstream>

// stringstream을 활용하여 특정 문자를 분리한다.
std::pair<std::string, std::string>& Split(const std::string& _Input)
{
	static std::pair<std::string, std::string> Result;

	std::stringstream ss(_Input);

	// 결과를 받을 임시버퍼
	static std::string Buffer;

	// 띄어쓰기를 구분하여 버퍼에 문자열을 저장하고 peek 위치를 옮긴다
	std::getline(ss, Buffer, ' ');
	Result.first = Buffer;
	std::getline(ss, Buffer, ' ');
	Result.second = Buffer;

	return Result;
}


// 선물을 많이 준 쪽이 1개 더 받는다.
// 선물 받은 기록이 없거나, 받은 선물의 수가 같을 경우
// 선물지수에 따라 누가 더 받을지 결정된다.
// 선물지수 = 준 선물 - 받은 선물

struct FUserInfo
{
	std::string Name;
	std::map<FUserInfo*, int> Record;
	int GiftIndex = 0;

	/* 선물 지수를 반환한다. */
	int GetGiftCOunt() const
	{
		int Result = 0;

		// 내가 선물해준 기록을 순회하면서 상대에게 준 선물과 
		// 선물지수에 따라 결과 값을 반환한다.
		for (const std::pair<FUserInfo*, int>& pair : Record)
		{
			const int GiveCount = pair.second;

			// 선물을 준 수가 0이하인 경우, 
			if (GiveCount < 0)
			{
				continue;
			}
			// 선물을 준 수가 동일하고 나의 선물 지수가 더 많을 경우
			else if (0 == GiveCount)
			{
				const FUserInfo* OtherInfo = pair.first;
				if (OtherInfo->GiftIndex < GiftIndex)
				{
					++Result;
				}
			}
			// 선물을 준 수가 상대보다 많으면
			else
			{
				++Result;
			}
		}
		return Result;
	}
};

int solution(std::vector<std::string> friends, std::vector<std::string> gifts) 
{
	int answer = 0;

	const int NUMBER_OF_FRIEND = static_cast<int>(friends.size());

	std::unordered_map<std::string, FUserInfo> Infos;
	Infos.reserve(NUMBER_OF_FRIEND);

	// 리소스 생성 
	for (int i = 0; i < NUMBER_OF_FRIEND; i++)
	{
		FUserInfo NewInfo; 
		NewInfo.Name = friends[i];
		Infos.insert(std::make_pair(friends[i], std::move(NewInfo)));
	}

	for (std::pair<const std::string, FUserInfo>& Mypair : Infos)
	{
		for (std::pair<const std::string, FUserInfo>& pair : Infos)
		{
			if (&Mypair.second != &pair.second)
			{
				Mypair.second.Record[&pair.second] = 0;
			}
		}
	}

	// 내가 상대에게 준 횟수를 기록
	// 내가 상대에게 받은 횟수를 기록
	for (const std::string& MSG : gifts)
	{
		std::pair<std::string, std::string> pair = Split(MSG);

		std::unordered_map<std::string, FUserInfo>::iterator TakerIter = Infos.find(pair.first);
		if (TakerIter == Infos.end())
		{
			// Error
			return -1;
		}

		std::unordered_map<std::string, FUserInfo>::iterator GiverIter = Infos.find(pair.second);
		if (GiverIter == Infos.end())
		{
			// Error
			return -1;
		}
		
		FUserInfo& TakerInfo = TakerIter->second;
		FUserInfo& GiverInfo = GiverIter->second;

		++TakerInfo.GiftIndex;
		++TakerInfo.Record[&GiverInfo];
		--GiverInfo.GiftIndex;
		--GiverInfo.Record[&TakerInfo];
	}

	for (const std::pair<std::string, FUserInfo>& info : Infos)
	{
		int GiftCount = info.second.GetGiftCOunt();
		answer = std::max(GiftCount, answer);
	}

	return answer;
}

int main()
{
	// solution({ "joy", "brad", "alessandro", "conan", "david" }, { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" });
	solution({ "muzi", "ryan", "frodo", "neo" }, { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" });
	// Split("Hello, World!. This is so Fun.");
    std::cout << "Hello World!\n";
}