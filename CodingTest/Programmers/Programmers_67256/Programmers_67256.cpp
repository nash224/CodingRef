// Programmers_67256.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>

#define WIDTH 3
#define HEIGHT 4

class Int2
{
public:
	Int2(int _x, int _y)
		:X(_x), Y(_y)
	{

	}

	static int Length(const Int2& _Idx1, const Int2& _Idx2)
	{
		const int X_Len = std::abs(_Idx1.X - _Idx2.X);
		const int Y_Len = std::abs(_Idx1.Y - _Idx2.Y);
		return X_Len + Y_Len;
	}

	int X = 0;
	int Y = 0;
};

class CHand
{
public:
	CHand(const Int2& _Index)
		:mIdx(_Index)
	{
	}

public:
	inline void Set(const Int2& _Index)
	{
		mIdx = _Index;
	}

	inline const Int2& Get() const
	{
		return mIdx;
	}

private:
	Int2 mIdx;
};

class CPhone
{
public:
	CPhone()
		: mLHand({ 0, 3 })
		, mRHand({ 2, 3 })
	{
	}

public:
	void SetHand(const std::string& _Hand)
	{
		mbLeft = (_Hand == "left");
	}

	char ToInput(int _Num)
	{
		// 숫자를 index로 변환
		char Result = 0;
		Int2 Idx = GetIndex(_Num);

		// 번호 1, 4, 7이면 왼손
		if (bool LeftPad = (0 == Idx.X))
		{
			mLHand.Set(Idx);
			Result = 'L';
		}
		// 번호 3, 6, 0면 오른손
		else if (bool RightPad = (2 == Idx.X))
		{
			mRHand.Set(Idx);
			Result = 'R';
		}
		// 번호 2, 5, 8이면 손 위치와 손잡이에 의해 결정됨
		else
		{
			if (true == IsLeftPress(Idx))
			{
				mLHand.Set(Idx);
				Result = 'L';
			}
			else
			{
				mRHand.Set(Idx);
				Result = 'R';
			}
		}

		return Result;
	}

private:
	Int2 GetIndex(int _Num)
	{
		if (0 == _Num)
		{
			return Int2(1, 3);
		}
		else if(0 < _Num || _Num < 10)
		{
			return Int2((_Num - 1) % 3, (_Num - 1) / 3);
		}
		
		return Int2(0, 0);
	}

	int Length(const Int2& _Idx1, const Int2& _Idx2) const
	{
		const int X_Len = std::abs(_Idx1.X - _Idx2.X);
		const int Y_Len = std::abs(_Idx1.Y - _Idx2.Y);
		return X_Len + Y_Len;
	}

	bool IsLeftPress(const Int2& _Idx)
	{
		const int Lenght_To_LH = Int2::Length(_Idx, mLHand.Get());
		const int Lenght_To_RH = Int2::Length(_Idx, mRHand.Get());
		if (Lenght_To_RH == Lenght_To_LH)
		{
			return mbLeft;
		}

		return Lenght_To_LH < Lenght_To_RH;
	}

private:
	bool mbLeft = false;
	CHand mLHand;
	CHand mRHand;

};


std::string solution(std::vector<int> numbers, std::string hand);

int main()
{
	solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");
    std::cout << "Hello World!\n";
}


std::string solution(std::vector<int> numbers, std::string hand)
{
	std::string answer = "";
	answer.reserve(numbers.size());

	// 손잡이 설정
	CPhone NewPhone;
	NewPhone.SetHand(hand);

	// 순회를 돌면서 번호를 누르고 
	// 손위치 반환
	for (const int Num : numbers)
	{
		char Hand = NewPhone.ToInput(Num);
		answer.push_back(Hand);
	}

	return answer;
}
