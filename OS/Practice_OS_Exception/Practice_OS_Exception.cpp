// Practice_OS_Exception.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

void InCrease(std::mutex& _m, int* _pValue, std::vector<int>::iterator _From, std::vector<int>::iterator _To);


int main()
{
	const int NUMBER_OF_THREADS = 5;
	const int TOTAL_COUNT = 10000;
	int Total = 0;

	std::mutex m;

	std::vector<std::thread> Jobs{ NUMBER_OF_THREADS };

	// Create Resource for Thread Job
	std::vector<int> Resource{ TOTAL_COUNT };
	for (int i = 0; i < TOTAL_COUNT; i++)
	{
		Resource.push_back(i);
	}

	// Thread Run
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		std::vector<int>::iterator StartIter = Resource.begin();
		auto Object = std::thread(InCrease,
			m, &Total, 
			StartIter + ((TOTAL_COUNT / NUMBER_OF_THREADS) * i),
			StartIter + ((TOTAL_COUNT / NUMBER_OF_THREADS) * (i + 1)));
		Jobs.push_back(Object);
	}

	// Wait for Job End
	for (std::thread& Thread: Jobs)
	{
		Thread.join();
	}

	// use resource
	std::cout << Total << std::endl;
}

void InCrease(std::mutex& _m, int* _pValue, std::vector<int>::iterator _From, std::vector<int>::iterator _To)
{
	int Sum = 0;

	for (; _From != _To; ++_From)
	{
		Sum += (*_From);
	}

	// Thread 구현부에서 Try 못하게 막아둠 
	// 에러처리 
	__try
	{
		_m.lock();

		(*_pValue) += Sum;
	}

	// 의도는 Try 실행블록을 빠져나오면 무조건 finally 가 실행되게 하려고 했음.
	// 현재 예외처리 상황이 존재하지 않지만 복잡한 작업을 요구할수록 예외처리할 분기문이 많아짐
	// 그래서 분기문을 없애고 예외처리 블록을 만들어, 한꺼번에 해결해주기 위해서 SEH를 문법을 이용
	__finally
	{
		_m.unlock();
	}
}