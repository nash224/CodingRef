#pragma once
#include <assert.h>

namespace my_math
{
	int max(int _v1, int _v2)
	{
		return _v1 < _v2 ? _v2 : _v1;
	}

	int min(int _v1, int _v2)
	{
		return _v1 < _v2 ? _v1 : _v2;
	}
}


template<typename T>
class MyVector
{
private:
	using size_type = int;

public:
	MyVector()
	{

	}

	MyVector(size_type _iSize)
	{
		if (_iSize <= 0)
		{
			// assert
			return;
		}

		_ReAlloc(_iSize);
	}

	~MyVector()
	{
		// 이동 생성자 메모리 해제 방지
		if (nullptr != mPtr)
		{
			delete[] mPtr;
			mPtr = nullptr;
		}
	}

	MyVector(const MyVector& _Other)
	{
		mCapacity = _Other.capacity();
		mSize = _Other.size();
		_ReAlloc(mCapacity);

		for (size_type i = 0; i < mSize; i++)
		{
			mPtr[i] = _Other.mPtr[i];
		}
	}

	MyVector(MyVector&& _Other) noexcept
	{
		mCapacity = _Other.capacity();
		mSize = _Other.size();

		mPtr = _Other.mPtr;
		_Other.mPtr = nullptr;
	}

	MyVector& operator=(const MyVector& _Other)
	{
		mCapacity = _Other.capacity();
		mSize = _Other.size();

		_ReAlloc(mCapacity);

		for (size_type i = 0; i < mSize; i++)
		{
			mPtr[i] = _Other.mPtr[i];
		}

		return *this;
	}

	MyVector& operator=(MyVector&& _Other)
	{
		mCapacity = _Other.capacity();
		mSize = _Other.size();

		mPtr= _Other.mPtr;
		_Other.mPtr = nullptr;

		return *this;
	}

public:
	// Random Acess
	T& operator[](size_type _Idx) const
	{
		if ((_Idx < 0) || (mSize < _Idx))
		{
			static T ErrorValue;
			// assert
			return ErrorValue;
		}

		return mPtr[_Idx];
	}

public:
	inline size_type size() const { return mSize; }
	inline size_type capacity() const { return mCapacity; }
	inline void empty() const { return (mSize == 0); }

	void reserve(size_type  _iCapacity)
	{
		mCapacity = my_math::max(mCapacity, _iCapacity);

		_ReAlloc(mCapacity);
	}

	void resize(size_type  _iSize)
	{
		if (_iSize < 0)
		{
			// assert
			return;
		}

		if (mSize < _iSize) // Realloc
		{
			_ReAlloc(_iSize);
		}
		else if (_iSize < mSize) // trim
		{
			for (size_type i = _iSize; i < mSize; i++)
			{
				mPtr[i] = NULL; 
			}
		}

		mSize = _iSize;
	}

	void push_back(const T& _Data)
	{
		if (mCapacity == mSize)
		{
			_ReAlloc((mCapacity * 2) + 1);
		}

		mPtr[mSize] = _Data;

		++mSize;
	}

	void pop_back()
	{
		if (mSize <= 0)
		{
			// assert
			return;
		}

		mPtr[mSize - 1] = NULL;

		--mSize;
	}

	// 배열을 앞에 항목을 삽입합니다.
	void push_front(const T& _Data)
	{
		if (mCapacity == mSize)
		{
			_ReAlloc((mCapacity * 2) + 1);
		}

		for (size_type i = mSize - 1; 0 <= i; --i)
		{
			mPtr[i + 1] = mPtr[i];
		}

		mPtr[0] = _Data;

		++mSize;
	}

	void pop_front()
	{
		if (mSize <= 0)
		{
			// assert
			return;
		}

		mPtr[0] = NULL;

		for (size_type i = 1; i < mSize; i++)
		{
			mPtr[i - 1] = mPtr[i];
		}


		--mSize;
	}

	void clear()
	{
		for (size_type i = 0; i < mSize; i++)
		{
			mPtr[i] = NULL;
		}

		mSize = 0;
	}

private:
	// 메모리 확장
	void _ReAlloc(size_type _iCapacity)
	{
		// 요청한 배열이 더 작으면 리턴
		if (_iCapacity < mCapacity)
		{
			return;
		}

		T* Temp = mPtr;
		mPtr = new T[_iCapacity];
		mCapacity = _iCapacity;

		for (size_type  i = 0; i < mSize; i++)
		{
			mPtr[i] = Temp[i];
		}

		if (nullptr != Temp)
		{
			delete[] Temp;
			Temp = nullptr;
		}
	}

private:
	size_type  mSize = 0;
	size_type  mCapacity = 0;
	T* mPtr = nullptr;

};

template<typename DataType>
void Display(const MyVector<DataType>& _vec)
{
	std::cout << "Capacity : " << _vec.capacity() << "\n";
	std::cout << "SIze : " << _vec.size() << "\n";

	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << ' ';
	}

	std::cout << '\n';
}