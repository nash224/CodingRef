// CPP_VirtualClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <limits>

void Print(const char* _Text)
{
	std::cout << _Text << '\n';
}

class Super
{
public:
	virtual void DoSomething() 
	{
		std::cout << "Super Something Work" << '\n';
	}

private:

};

class Sub : public Super
{
public:
	void DoSomething() override
	{
		__super::DoSomething();

		std::cout << "Sub Something Work" << '\n';
	}

private:

};

class Sub2 : public Super
{

};

class CAnimal
{
public:
	CAnimal()
	{

	}

	// 하나라도 가상함수가 선언되어 있다면 
	// 소멸자의 순서가 꼬이지 않게 virtual 메서드를 선언해준다.
	virtual ~CAnimal()
	{

	}

public:
	virtual void Feed()
	{
		// 아무것도 하지 않는다.
	}

	// 순수 가상함수로 선언하여 자식 클래스에게 인터페이스만 제공한다.
	virtual void Sleep() = 0;
	virtual void Walk() = 0;

protected:
	// 자식 클래스가 해당 특성을 물려받는다.
	int m_iAge = 0;

};

class CRabbit : public CAnimal
{
public:
	void Feed() override
	{
		// 부모 클래스의 코드를 재사용한다.
		CAnimal::Feed();

		std::cout << "Mogu Mogu" << '\n';
	}

	// 무조건 메서드가 재정의되어져야 한다.
	void Sleep() override
	{
		std::cout << "Zzz.." << '\n';
	}
	
	void Walk() override
	{
		Print("lightly.. lightly..");
	}

private:


};

class CDog : public CAnimal
{
public:
	CDog()
		:m_dValue(std::numeric_limits<double>::quiet_NaN()) // nan으로 초기화한다.
	{

	}

public:
	void Feed() override
	{
		// 부모 클래스의 코드를 재사용한다.
		CAnimal::Feed();

		std::cout << "Yum Yum" << '\n';
	}

	// 무조건 메서드가 재정의되어져야 한다.
	void Sleep() override
	{
		std::cout << "Zzzzz.." << '\n';
	}
	
	void Walk() override
	{
		// 순수 가상함수로 선언된 메서드를 명시적으로 호출할 수 없다.
		// Linker Error! : 컴파일러가 찾지 않는다.
		// CAnimal::Walk(); 

		Print("Walllllk");
	}

private:
	double m_dValue;

};

int main()
{
	if (false)
	{
		Sub NewSub;
		Super NewSuper = NewSub;
		Super& RefSuper = NewSub;
		Sub2& RefSub2Pointer = dynamic_cast<Sub2&>(RefSuper);
		NewSub.DoSomething();
	}

	if (true)
	{
		CAnimal* Arr[2] = {nullptr,};
		// CAnimal NewAnimal; 가삼함수이기 때문에 인스턴스 되지 않는다.

		CRabbit NewRabbit;
		CDog NewDog;

		Arr[0] = &NewRabbit;
		Arr[1] = &NewDog;

		for (int i = 0; i < 2; i++)
		{
			if (nullptr != Arr[i])
			{
				// 부모의 인터페이스로 실제 객체가 정의한 메서드를 호출한다.
				Arr[i]->Sleep(); 
				Arr[i]->Walk(); 
			}
		}
	}
}
