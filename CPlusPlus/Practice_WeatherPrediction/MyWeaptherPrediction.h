#pragma once
#include "Weather.h"

/**
* 
*/
class MyWeaptherPrediction : public WeatherPredection
{
public:
	void SetCurrentTempFaphrenheit(int _InTemp) override;
	int GetTomorrowTempFaphrenheit() const override;
	void ShowResult() const override;

private:
	static int ConvertCelsiusToFahrenheit(int _InCelsius) {}
	static int ConvertFahrenheitToCelsius(int _InFahrenheit) {}

private:

};