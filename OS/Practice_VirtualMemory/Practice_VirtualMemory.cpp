// Practice_VirtualMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

int main()
{
	SYSTEM_INFO si;
	DWORD AllocGranularity;
	DWORD PageSize;

	GetSystemInfo(&si);
	PageSize = si.dwPageSize;
	AllocGranularity = si.dwAllocationGranularity;

	std::cout << "Page Size : " << PageSize / 1024 << " Kbyte \n"; // Page Size : 4 Kbyte
	std::cout << "Allocation Granularity :" << AllocGranularity / 1024 << "Kbyte \n"; // Allocation Granularity : 64Kbyte
	return 1;
}