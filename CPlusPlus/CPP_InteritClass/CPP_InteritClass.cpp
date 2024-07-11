// CPP_InteritClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Super
{
public:
	Super() {}

public:
	virtual void SomeMethod()
	{
		std::cout << "Call Super Method! \n";
	}

protected:
	int mProtectedInt = 0;

private:
	int mPrivateInf = 0;

};

class Sub final : public Super
{
public:
	Sub() {}

public:
	void SomeMethod() override
	{
		std::cout << "Call Sub Method!";
	}

	void SomeOtherMethod()
	{
		std::cout << "Call Sub Other Method! \n";
	}

};

int main()
{
	if (false)
	{
		Sub NewSub;
		NewSub.SomeMethod();

		Super NewSuper;
		// NewSuper.SomeOtherMethod(); // Error! 
	}

	if (false)
	{
		Sub NewSub;
		Super* pSub = &NewSub;
		pSub->SomeMethod();
		// pSub->SomeOtherMethod(); // Error! 부모 포인터는 자식의 메서드를 모른다.
	}

	if (true)
	{
		Super* pNewSub = new Sub();
		pNewSub->SomeMethod(); // Call Sub Other Method! 
		delete pNewSub;
	}
}
