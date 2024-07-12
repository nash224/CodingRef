#pragma once

/**
* 
*/
class mONSTER
{
public:
	mONSTER();
	~mONSTER();

	mONSTER(const mONSTER& _Other) = delete;
	mONSTER(mONSTER&& _Other) noexcept = delete;
	mONSTER& operator=(const mONSTER& _Other) = delete;
	mONSTER& operator=(mONSTER&& _Other) noexcept = delete;

private:

};