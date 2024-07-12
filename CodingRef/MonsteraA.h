#pragma once

/**
* 
*/
class MonsteraA
{
public:
	// constructor deconstructor
	MonsteraA();
	~MonsteraA();

	// delete function
	MonsteraA(const MonsteraA& _Other) = delete;
	MonsteraA(MonsteraA&& _Other) noexcept = delete;
	MonsteraA& operator=(const MonsteraA& _Other) = delete;
	MonsteraA& operator=(MonsteraA&& _Other) noexcept = delete;

private:

};