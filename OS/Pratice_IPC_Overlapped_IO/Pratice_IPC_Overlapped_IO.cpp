// Pratice_IPC_Overlapped_IO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

#define BUF_SIZE 1024
int CommToClient(HANDLE);

int main()
{
	LPCWSTR PipName = _T("\\\\.\\pip\\simple_pipe");
	HANDLE hPipe;
	while (true)
	{
		hPipe = CreateNamedPipe(
			PipName, 
			PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
			PIPE_UNLIMITED_INSTANCES,
			BUF_SIZE / 2,
			BUF_SIZE / 2,
			20000, NULL);
	}

	if (nullptr == hPipe)
	{
		std::cout << "CreateNamedPip failed! \n";
	}

	BOOL isSuccess = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
	if (NULL == isSuccess)
	{
		CommToClient(hPipe);
	}
	else
	{
		CloseHandle(hPipe);
	}

	return 1;
}

int CommToClient(HANDLE _hPipe)
{
	TCHAR FileName[MAX_PATH] = {};
	TCHAR DataBuf[BUF_SIZE];
	BOOL isSuccess;
	DWORD FileNameSize;

	isSuccess = ReadFile(
		_hPipe, FileName,
		MAX_PATH * sizeof(TCHAR),
		&FileNameSize, NULL);

	if (false == isSuccess || 0 == FileNameSize )
	{
		_tprintf(_T("Pipe read message error! \n"));
		return -1;
	}

	FILE* pFile = _tfopen(FileName, _T("r"));
	if (nullptr == pFile)
	{
		_tprintf(_T("File open fault\n"));
		return -1;
	}

	OVERLAPPED OverlappedInst;
	memset(&OverlappedInst, 0, sizeof(OverlappedInst));
	OverlappedInst.hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);

	DWORD ByteWritten, BytesRead = 0;
	DWORD ByteWrite, ByteTransfer = 0;

	while (false == feof(pFile))
	{
		BytesRead = fread(DataBuf, 1, BUF_SIZE, pFile);
		ByteWrite = BytesRead;
		isSuccess = WriteFile(_hPipe, DataBuf, ByteWrite, &ByteWritten, &OverlappedInst);
		if (false == isSuccess && GetLastError() != ERROR_IO_PENDING)
		{
			_tprintf(_T("Pipe write message error! \n"));
			break;
		}

		WaitForSingleObject(OverlappedInst.hEvent, INFINITE);
		GetOverlappedResult(_hPipe, &OverlappedInst, &ByteTransfer, FALSE);

		_tprintf(_T("transferred data size : %u \n"), ByteTransfer);
	}

	FlushFileBuffers(_hPipe);
	DisconnectNamedPipe(_hPipe);
	CloseHandle(_hPipe);
	return 1;
}