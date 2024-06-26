// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <crtdbg.h>
#include <iostream>
#include <vector>
#include "MyVector.h"
#include <string>

template<typename DataType>
void Print(DataType _Data)
{
	std::cout << _Data << std::endl;
}

void Print(const std::string& _Text);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	if (true)
	{
		class Monster
		{
		public:
			int mHp = 0;
			
		};

		std::vector<Monster> Array(5);
		Array.reserve(2);
		Array.resize(1);

		std::vector<Monster>::iterator StartIter = Array.begin();

		int a = 0;
	}

	if (false)
	{
		std::cout << "========== resize, reserve 예제 ==========" << std::endl;

		MyVector<int> Arr;

		Print("reserve : 3");
		Arr.reserve(3);
		Display(Arr);

		Print("reserve : 2");
		Arr.reserve(2); 
		Display(Arr);

		Print("reserve : 7");
		Arr.reserve(7); 
		Display(Arr);

		Print("reserve : 5");
		Arr.resize(5);
		Display(Arr);

		Print("reserve : 3");
		Arr.resize(3);
		Display(Arr);

		Print("reserve : 7");
		Arr.resize(7);
		Display(Arr);

		int a = 0;
	}

	if (true)
	{
		std::cout << "========== push_back, pop_back 예제 ==========" << std::endl;

		MyVector<int> Arr;

		for (int i = 0; i < 10; i++)
		{
			Arr.push_back(i);
			Display(Arr);
		}

		Print("Pop Back");
		Arr.pop_back();
		Display(Arr);
		Print("Pop Back");
		Arr.pop_back();
		Display(Arr);
		Print("Pop Back");
		Arr.pop_back();
		Display(Arr);
		Print("Pop Back");
		Arr.pop_back();
		Display(Arr);
	}

	if (true)
	{
		std::cout << "========== push_front, pop_front 예제 ==========" << std::endl;

		MyVector<int> Arr;

		for (int i = 0; i < 10; i++)
		{
			Arr.push_front(i);
			Display(Arr);
		}

		Arr.pop_front();
		Display(Arr);
		Arr.pop_front();
		Display(Arr);
		Arr.pop_front();
		Display(Arr);
		Arr.pop_front();
		Display(Arr);

		Arr.clear();
		Display(Arr);
	}

	// 노드 개념을 추가하기 귀찮아서 미구현
	if (false)
	{
		std::cout << "========== 반복자 구현 예제 ==========" << std::endl;

		MyVector<int> Arr;


		for (int i = 0; i < 10; i++)
		{
			Arr.push_back(i);
		}

		Display(Arr);
	}
}

void Print(const std::string& _Text)
{
	std::cout << _Text << std::endl;
}