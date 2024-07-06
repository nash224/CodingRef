#include "CSpreadsheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

CSpreadsheetCell::CSpreadsheetCell()
{

}

CSpreadsheetCell::CSpreadsheetCell(double _dValue)
{
	SetValue(_dValue);
}

CSpreadsheetCell::CSpreadsheetCell(const std::string& _String)
{
	SetString(_String);
}

void CSpreadsheetCell::SetValue(double _InValue)
{
	mValue = _InValue;
	mString = DoubletoString(_InValue);
}

double CSpreadsheetCell::GetValue() const
{
	return mValue;
}

void CSpreadsheetCell::SetString(const std::string& _InString)
{
	mString = _InString;
	mString = StringToDouble(_InString);
}

const std::string& CSpreadsheetCell::GetString() const
{
	return mString;
}


std::string CSpreadsheetCell::DoubletoString(double _InValue) const
{
	ostringstream OStr;
	OStr << _InValue;
	return OStr.str();
}

double CSpreadsheetCell::StringToDouble(const std::string& _InString) const
{
	double temp;
	istringstream iStr(_InString);
	iStr >> temp;
	if (iStr.fail() || (false == iStr.eof()))
	{
		return 0.0;
	}

	return temp;
}