#include "CSpreadsheet.h"

int CSpreadsheet::s_Counter = 0;
CSpreadsheet::~CSpreadsheet() 
{
	Release();
}

void CSpreadsheet::SetCellAt(int _x, int _y, CSpreadsheetCell& _Cell)
{
	ppCell[_y][_x] = _Cell;
}

void CSpreadsheet::_Alloc()
{
	ppCell = new CSpreadsheetCell* [mHeight];

	for (int i = 0; i < mHeight; i++)
	{
		ppCell[i] = new CSpreadsheetCell[mWidth];
	}
}

void CSpreadsheet::Release()
{
	if (nullptr != ppCell)
	{
		for (int i = 0; i < mHeight; i++)
		{
			delete[] ppCell[i];
		}

		delete[] ppCell;
		ppCell = nullptr;
	}
}

void CSpreadsheet::Copy(const CSpreadsheet& _Src)
{
	if (mHeight != _Src.mHeight || mWidth != _Src.mWidth)
	{
		mWidth = _Src.mWidth;
		mHeight = _Src.mHeight;

		Release();
		_Alloc();
	}

	for (int y = 0; y < mHeight; y++)
	{
		for (int x = 0; x < mWidth; x++)
		{
			ppCell[y][x] = _Src.ppCell[y][x];
		}
	}
}


bool CSpreadsheet::InRangce(int _iWidth, int _iHeight) const
{
	if (mWidth < _iWidth || mHeight < _iHeight)
	{
		throw std::exception("Out of Range");
	}

	return true;
}