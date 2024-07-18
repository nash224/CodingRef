#pragma once
#include <string>

class WeatherPredection
{
public:
	virtual ~WeatherPredection()
	{

	}

	virtual void SetCurrentTempFaphrenheit(int _InTemp) {}
	virtual void SetPositionOfJupiter(int _InDistanceFromMars) {}
	virtual int GetTomorrowTempFaphrenheit() const {}
	virtual double GetChanceOfRain() const {}
	virtual void ShowResult() const {}
	virtual std::string GetTemperature() const {}


private:
	int iCurrentTempFaphrenheit;
	int iDistanceFromMars;

};