// Programmers_155652.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>


class CEncryption
{
public:
	// 기본생성자가 있으면 안되는 이유 
	// 생성자 초기화 리스트에서 상수 멤버변수를 초기화해주고 있음.
	// 그런데 디폴트 생성자가 있으면 생성자가 먼저 호출하는데, 이걸 어떻게 초기화해주지?
	// 이런 상황에서 컴파일러는 에러를 발생시킨다.
	// CEncryption() {}

	CEncryption(const std::string& _Skip , const int& _Index)
		: mSkip(_Skip), mIndex(_Index)
	{

	}

	~CEncryption() {}

public:
	void Decode(std::string* _pDest, const std::string& _Src);

protected:
	bool IsOverChar(char _c) const;

private:
	const std::string mSkip;
	const int mIndex;

};

std::string solution(std::string s, std::string skip, int index)
{
	std::string Answer;

	CEncryption NewEncrption{ skip, index };
	NewEncrption.Decode(&Answer, s);

	return Answer;
}

int main()
{
	std::string DecodedText = solution("aukks", "wbqd", 5);
	std::cout << DecodedText << std::endl;
}

void CEncryption::Decode(std::string* _pDest, const std::string& _Src)
{
	const int SOURCE_SIZE = static_cast<int>(_Src.size());

	std::string DecodeString;
	DecodeString.reserve(SOURCE_SIZE);

	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		char Char = _Src[i];

		for (int i = 0; i < mIndex; i++)
		{
			do
			{
				Char += 1;
				if (true == IsOverChar(Char))
				{
					Char = 'a';
				}

			} while (std::string::npos != mSkip.find_first_of(Char));
		}

		DecodeString.push_back(Char);
	}

	(*_pDest) = DecodeString;
}

bool CEncryption::IsOverChar(char _c) const
{
	return 'z' < _c;
}