// Practice_Heap_AllocAndFree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

int main()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	const UINT PageSize = si.dwPageSize;

	// 힙 생성
	HANDLE hHeap = HeapCreate(HEAP_NO_SERIALIZE, PageSize * 10, PageSize * 100);
	if (nullptr == hHeap)
	{
		std::cout << "Create Failed";
		return -1;
	}

	// 힙 메모리 할당
	int* Ptr = static_cast<int*>(HeapAlloc(hHeap, 0, sizeof(int) * 10));
	if (nullptr == Ptr)
	{
		std::cout << "Alloc Failed";
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		Ptr[i] = i;
	}

	// 메모리 해제
	BOOL bFreeSucceeded = HeapFree(hHeap, 0, Ptr);
	if (!bFreeSucceeded)
	{
		std::cout << "Free Failed";
		return -1;
	}

	// 힙소멸
	BOOL bDestroy = HeapDestroy(hHeap);
	if (!bDestroy)
	{
		std::cout << "Destroy Failed";
		return -1;
	}
}
