#pragma once
#include "MyWeaptherPrediction.h"

MyWeaptherPrediction::MyWeaptherPrediction()
{
}

MyWeaptherPrediction::~MyWeaptherPrediction()
{
}

void MyWeaptherPrediction::SetCurrentTempFaphrenheit(int _InTemp)
{
	int FahrenhheitTemp = ConvertCelsiusToFahrenheit(_InTemp);
	SetCurrentTempFaphrenheit(FahrenhheitTemp);
}

int MyWeaptherPrediction::GetTomorrowTempFaphrenheit() const
{

}
