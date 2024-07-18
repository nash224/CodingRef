// VirtualMethod.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Print(const char* _Text = "");

class SomeClass
{
public:
	SomeClass()
	{
		Print("2. Call Some Calss");
	}

};

class IDebugInterface
{
public:
	void SetDebug(bool _Value)
	{
		bDebug = _Value;
	}

	bool GetDebug() const { return bDebug; }

private:
	bool bDebug = false;
};

class Super : public IDebugInterface
{
public:
	Super()
	{
		Print("Call Super Constructor");
	}

	Super(bool _bDebug)
	{
		SetDebug(_bDebug);

		if (true == GetDebug())
		{
			Print("1. Call Super Constructor");
		}
	}

	Super(int _Number)
	{
		SomeOfMethod();
	}

	virtual ~Super()
	{
		Print("Call Super Destructor");
	}

public:
	virtual void SomeOfMethod()
	{
		Print("Call Super Method");
	}


private:

};

class Sub : public Super
{
public:
	Sub()
	{
		Print("Call Sub Constructor");
	}

	Sub(bool _bDeubg)
		: Super(_bDeubg)
	{
		if (true == GetDebug())
		{
			Print("3. Call Sub Constructor");
		}
	}

	Sub(int _Number)
		: Super(_Number)
	{

	}

	~Sub()
	{
		Print("Call Sub Destructor");
	}

public:
	void SomeOfMethod() override final
	{
		Print("Call Sub Method");
	}

	void SomeOfSubMethod()
	{

	}

private:
	SomeClass mSome;

};

//class SubSub : public Sub
//{
//public:
//	void SomeOfMethod() override;
//
//private:
//
//};






int main()
{
	if (false)
	{
		// Super NewSuper;

		Sub NewSub;
		Super* pSub = &NewSub;
		pSub->SomeOfMethod();
		// pSub->SomeOfSubMethod(); // Error : Not Access 
	}

	if (false)
	{
		Super NewSuper;

		// 스택에서 Super객체에 Sub객체를 대입한다..
		{
			Sub NewSub;
			NewSuper = NewSub;
			// 디버깅 On
			NewSuper.SetDebug(true);
		}

		// virtual 메서드를 호출한다. 하지만 Sub의 메서드가 호출되지 않을 것이다.
		// 왜냐하면 이 객체는 본질적으로 Super 객체이기 때문에 컴파일러는 Sub객체를 알도리가 없다.
		NewSuper.SomeOfMethod();
	}

	if (true)
	{
		// Sub NewSub(true);
		Sub NewSub(1);
	}
}

void Print(const char* _Text)
{
	std::cout << _Text << '\n';
}