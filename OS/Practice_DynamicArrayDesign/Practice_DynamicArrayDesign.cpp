// Practice_DynamicArrayDesign.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

#define MAX_PAGE 10

int* NestPageAddress;
DWORD PageCount = 0;
DWORD PageSize = 0;
int PageFaultExceptionFilter(DWORD);

int main()
{
	LPVOID BAseAddress = nullptr;
	int* lpPtr = nullptr;
	SYSTEM_INFO si;

	GetSystemInfo(&si); // 현제 프로세스 정보 획득
	PageSize = si.dwPageSize;

	// 할당
	BAseAddress = VirtualAlloc(
		NULL, 
		MAX_PAGE * PageSize,
		MEM_RESERVE,
		PAGE_NOACCESS);

	if (nullptr == BAseAddress)
	{
		std::cout << "VirtualAlloc reserve failed!\n";
		return -1;
	}

	lpPtr = static_cast<int*>(BAseAddress);
	NestPageAddress = static_cast<int*>(BAseAddress);

	// 페이지 할당
	for (int i = 0; i < MAX_PAGE * PageSize / sizeof(int); i++)
	{
		// 페이지 만큼 할당했는데 실패하면 exception 예외로 가서 메모리 크기를 할당한다.
		__try
		{
			lpPtr[i] = i;
		}
		__except(PageFaultExceptionFilter(GetExceptionCode()))
		{
			ExitProcess(GetLastError());
		}
	}

	// 메모리 해제
	BOOL bSucceed = VirtualFree(BAseAddress, 0, MEM_RELEASE);
	if (bSucceed)
	{
		std::cout << " Release Succeeded!\n";
	}
	else
	{
		std::cout << "Release Failed!\n";
	}
}

int PageFaultExceptionFilter(DWORD _ExceptCode)
{
	// Not Page Fault
	if (_ExceptCode != EXCEPTION_ACCESS_VIOLATION)
	{
		std::cout << "Exception Code : " << _ExceptCode << '\n';
		return EXCEPTION_EXECUTE_HANDLER; // exception으로 가서 실행 후, 시스템을 끄지 않겠다.
	}
	std::cout << "Exception is a Page fault \n";

	// 최대 페이지를 초과하면 터트림
	if (PageCount >= MAX_PAGE)
	{
		std::cout << "Exception : Out of Page \n";
		return EXCEPTION_EXECUTE_HANDLER;
	}


	LPVOID lpvResult = VirtualAlloc(
		static_cast<LPVOID>(NestPageAddress),
		PageSize,
		MEM_COMMIT,
		PAGE_READWRITE);
	if (nullptr == lpvResult)
	{
		std::cout << "VirtualAlloc Failed \n";
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else
	{
		std::cout << "Allocating another Page \n";
	}

	++PageCount;
	NestPageAddress += PageSize/ sizeof(int);

	return EXCEPTION_CONTINUE_EXECUTION; // 돌아가서 정상 실행 exception을 들리지 않음
}