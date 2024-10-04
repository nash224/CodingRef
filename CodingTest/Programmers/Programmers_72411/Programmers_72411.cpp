﻿// Programmers_72411.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

void Recursive(const std::string& _Vec, std::string& _Buffer, int _Level, int _Count, std::vector<std::string>& _Result) 
{
	if (static_cast<int>(_Buffer.size()) == _Count)
	{
		_Result.push_back(_Buffer);
		return;
	}

	for (int i = _Level; i < _Vec.size(); ++i) 
	{
		_Buffer.push_back(_Vec[i]);
		Recursive(_Vec, _Buffer, i + 1, _Count, _Result);
		_Buffer.pop_back();
	}
}

std::vector<std::string> Combination(const std::string& _Vec, int _Count) 
{
	std::vector<std::string> Result;
	std::string Buffer;
	Recursive(_Vec, Buffer, 0, _Count, Result);
	return Result;
}

std::vector<std::string> FindCourse(const std::vector<std::string>& _Res, int _Count)
{
	std::vector<std::string> Results;

	std::set<std::string> AllCases;

	// 모든 경우의 수
	for (const std::string& Str : _Res)
	{
		std::vector<std::string> Cases = Combination(Str, _Count);
		for (const std::string& Case : Cases)
		{
			AllCases.insert(Case);
		}
	}

	int Count = 0;
	int TopValue = 0;
	for (const std::string& Case : AllCases)
	{
		Count = 0;
		for (const std::string& Str : _Res)
		{
			bool bContain = std::all_of(Case.begin(), Case.end(), [&Str](char CHAR)
				{
					return std::string::npos != Str.find(CHAR);
				});

			if (true == bContain)
			{
				++Count;
			}
		}

		if (Count < 2)
		{
			continue;
		}

		if (TopValue < Count)
		{
			TopValue = Count;
			Results.clear();
			Results.push_back(Case);
		}
		else if (Count == TopValue)
		{
			Results.push_back(Case);
		}
	}

	return Results;
}

std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course)
{
	std::vector<std::string> answer;
	answer.reserve(course.size());

	// 주문을 순회하면서 주문했던 음식을 전부 오름차순으로 정렬
	for (std::string& Order : orders)
	{
		std::sort(Order.begin(), Order.end());
	}

	for (int Count : course)
	{
		std::vector<std::string> Courses = FindCourse(orders, Count);
		for (const std::string& Course : Courses)
		{
			answer.push_back(Course);
		}
	}

	std::sort(answer.begin(), answer.end());
	
	return answer;
}

int main()
{
	solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    std::cout << "Hello World!\n";
}