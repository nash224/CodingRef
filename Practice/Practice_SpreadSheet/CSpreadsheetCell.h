#pragma once
#include <string>

// Ό³Έν :
class CSpreadsheetCell
{
public:
	CSpreadsheetCell();
	CSpreadsheetCell(double _dValue);
	CSpreadsheetCell(const std::string& _String);
	CSpreadsheetCell(const CSpreadsheetCell& _Ohter)
		: mValue(_Ohter.mValue), mString(_Ohter.mString)
	{

	}

	CSpreadsheetCell operator+(const CSpreadsheetCell& _Other)
	{
		return CSpreadsheetCell(mValue + _Other.mValue);
	}

public:
	void SetValue(double _InValue);
	double GetValue() const;
	void SetString(const std::string& _InString);
	const std::string& GetString() const;

protected:

private:
	std::string DoubletoString(double _InValue) const;
	double StringToDouble(const std::string& _InString) const;

private:
	double mValue = 0.0;
	std::string mString;

};

