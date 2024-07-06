#pragma once

#include "CSpreadsheetCell.h"

// Ό³Έν :
class SpreadsheetApplication;
class CSpreadsheet
{
private:
	static int GetCounter() { return s_Counter; }

private:
	static int s_Counter;
	static const int MAX_WIDTH = 100;
	static const int MAX_HEIGHT = 100;

public:
	// constrcuter destructer
	CSpreadsheet(int _iWidth, int _iHeight)
		: mWidth(_iWidth < MAX_WIDTH ? MAX_WIDTH : _iWidth)
		, mHeight(_iHeight < MAX_HEIGHT ? MAX_HEIGHT : _iHeight)
		, mId(s_Counter)
	{
		++s_Counter;
		_Alloc();
	}

	CSpreadsheet(const CSpreadsheet& _Other)
		: mWidth(_Other.mWidth)
		, mHeight(_Other.mHeight)
		, mId(s_Counter)
	{
		++s_Counter;
		Copy(_Other);
	}

	~CSpreadsheet();

	CSpreadsheet& operator=(const CSpreadsheet& _Other)
	{
		if ((*this) == _Other)
		{
			return *this;
		}

		Release();

		mWidth = _Other.mWidth;
		mHeight = _Other.mHeight;

		Copy(_Other);

		return *this;
	}

	bool operator==(const CSpreadsheet& _Other) const
	{
		return (*this) == _Other;
	}

	bool operator!=(const CSpreadsheet& _Other) const
	{
		return (*this) != _Other;
	}

public:
	void SetCellAt(int _x, int _y, class CSpreadsheetCell& _Cell);

private:
	void _Alloc();
	void Release();
	void Copy(const CSpreadsheet& _Src);
	bool InRangce(int _iWidth, int _iHeight) const ;

protected:

private:
	const int mId = 0;
	int mWidth = 0;
	int mHeight = 0;
	CSpreadsheetCell** ppCell = nullptr;
	SpreadsheetApplication* pApp = nullptr;

};

