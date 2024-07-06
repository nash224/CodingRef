// Practice_APCQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

VOID CALLBACK APCProc(ULONG_PTR);

int main()
{
	HANDLE hThread = GetCurrentThread();

	QueueUserAPC(APCProc, hThread, (ULONG_PTR)1);
	QueueUserAPC(APCProc, hThread, (ULONG_PTR)2);
	QueueUserAPC(APCProc, hThread, (ULONG_PTR)3);
	QueueUserAPC(APCProc, hThread, (ULONG_PTR)4);
	QueueUserAPC(APCProc, hThread, (ULONG_PTR)5);

	Sleep(5000); // Sleep for 5sec
	SleepEx(INFINITE, TRUE); // Thread will Wake up , If Alertable State is true.
	return 0;
}

VOID CALLBACK APCProc(ULONG_PTR _dwParam)
{
	_tprintf(_T("Asynchronous procedure call num %u\n"), (DWORD)_dwParam);
}