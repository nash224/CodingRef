// Practice_IPC_CompletionRutine_IO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

TCHAR StrData[] = 
	_T("Lorem Ipsum is simply dummy text of the printing and typesetting industry.")
	_T("Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,")
	_T("when an unknown printer took a galley of type and scrambled it to make a type specimen book. ")
	_T("It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.")
	_T("It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages,")
	_T("and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");

VOID WINAPI FileIOCompletionRoutine(DWORD, DWORD, LPOVERLAPPED);

int main()
{
	TCHAR FileName[] = _T("data.txt");
	HANDLE hFile = CreateFile(FileName, 
		GENERIC_WRITE, FILE_SHARE_WRITE, 0, 
		CREATE_ALWAYS, FILE_FLAG_OVERLAPPED, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File create fault!"));
		return -1;
	}

	OVERLAPPED OverlappedInst;
	memset(&OverlappedInst, 0, sizeof(OverlappedInst));
	OverlappedInst.hEvent = (HANDLE)1234;
	WriteFileEx(hFile, StrData, sizeof(StrData), &OverlappedInst, FileIOCompletionRoutine);

	SleepEx(INFINITE, TRUE);
	CloseHandle(hFile);
	return 1;
}

VOID WINAPI FileIOCompletionRoutine(DWORD _ErrorCode, DWORD _NumOfBytesTransfered, LPOVERLAPPED _Overlapped)
{
	_tprintf(_T("*************** File write result *************** \n"));
	_tprintf(_T("Error code : %u \n"), _ErrorCode);
	_tprintf(_T("Transfered bytes len : %u \n"), _NumOfBytesTransfered);
	_tprintf(_T("The other info : %u \n"), (DWORD)_Overlapped->hEvent);
}