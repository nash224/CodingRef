// Programmers_92334.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

void Split(std::string_view _Report)
{
	std::string Reporter;
	std::string Reportee;
}

struct FUserInfo
{
	int mID;
	std::string mName;
	std::vector<bool> mRecord;

};

std::vector<int> solution(std::vector<std::string> id_list, std::vector<std::string> report, int k)
{
	const int USER_NUMBER = static_cast<int>(id_list.size());
	std::vector<int> answer;
	std::vector<FUserInfo> UserInfos(USER_NUMBER);

	int iUserCount = 0;

	for (std::string_view Name : id_list)
	{
		FUserInfo& NewInfo = UserInfos.emplace_back();
		NewInfo.mID = iUserCount++;
		NewInfo.mName = Name;
		NewInfo.mRecord.resize(USER_NUMBER);
	}


	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}