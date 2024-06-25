#pragma once

#include <assert.h>

template<typename T>
class NyLinkedListNode
{
	template<typename T>
	friend class MyList;

	template<typename T>
	friend class LinkedListIteractor;

public:
	NyLinkedListNode()
	{

	}

	NyLinkedListNode(const T& _Data)
		: mData(_Data)
	{

	}

	~NyLinkedListNode()
	{

	}

private:
	T mData;
	NyLinkedListNode<T>* mPrev = nullptr;
	NyLinkedListNode<T>* mNext = nullptr;

};

template<typename T>
class LinkedListIteractor
{
	template<typename T>
	friend class MyList;

private:
	using Node = NyLinkedListNode<T>;

public:
	LinkedListIteractor()
	{

	}

	~LinkedListIteractor()
	{

	}

	LinkedListIteractor operator=(const LinkedListIteractor& _Other)
	{
		mNode = _Other.mNode;
		return (*this);
	}

	bool operator==(const LinkedListIteractor& _Other) const
	{
		return (_Other.mNode == mNode);
	}

	bool operator!=(const LinkedListIteractor& _Other) const
	{
		return (_Other.mNode != mNode);
	}

	T& operator*()
	{
		if (nullptr == mNode)
		{

		}

		return mNode->mData;
	}

	T& operator->()
	{
		if (nullptr == mNode)
		{

		}

		return mNode->mData;
	}

	void operator++()
	{
		mNode = mNode->mNext;
	}

	void operator++(int)
	{
		mNode = mNode->mNext;
	}

	void operator--()
	{
		mNode = mNode->mPrev;
	}

	void operator--(int)
	{
		mNode = mNode->mPrev;
	}


private:
	Node* mNode = nullptr;

};

template<typename T>
class MyList
{
private:
	using Node = NyLinkedListNode<T>;

public:
	using iterator = LinkedListIteractor<T>;


public:
	MyList()
	{
		mBeginNode = new Node;
		mEndNode = new Node;

		mBeginNode->mNext = mEndNode;
		mEndNode->mPrev = mBeginNode;
	}

	~MyList()
	{
		Node* pDeleteNode = mBeginNode;
		Node* pNextNode = pDeleteNode->mNext;

		while (nullptr != pNextNode)
		{
			pNextNode = pDeleteNode->mNext;
			delete pDeleteNode;
			pDeleteNode = pNextNode;
		}
	}

public:
	int size() const { return mSize; }
	bool empty() const { return (0 == mSize); }

	void push_back(const T& _Data)
	{
		Node* pNode = new Node(_Data);

		Node* pPrevNode = mEndNode->mPrev;

		pPrevNode->mNext = pNode;
		pNode->mPrev = pPrevNode;

		pNode->mNext = mEndNode;
		mEndNode->mPrev = pNode;
	}

	void push_front(const T& _Data)
	{
		Node* pNode = new Node(_Data);

		Node* pNextNode = mBeginNode->mNext;

		pNextNode->mPrev = pNode;
		pNode->mNext = pNextNode;

		pNode->mPrev = mBeginNode;
		mBeginNode->mNext = pNode;
	}

	void pop_back()
	{
		if (true == empty())
		{
			assert("");
		}

		Node* pDeleteNode = mEndNode->mPrev;
		Node* pPrevNode = pDeleteNode->mPrev;

		pPrevNode->mNext = mEndNode;
		mEndNode->mPrev = pPrevNode;

		delete pDeleteNode;
	}

	void pop_front()
	{
		if (true == empty())
		{
			assert("");
		}

		Node* pDeleteNode = mBeginNode->mNext;
		Node* pNextNode = pDeleteNode->mNext;

		pNextNode->mPrev = mBeginNode;
		mBeginNode->mNext = pNextNode;

		delete pDeleteNode;
	}

	T& front()
	{
		if (true == empty())
		{
			assert("");
		}

		return mBeginNode->mNext->mData;
	}

	T& back()
	{
		if (true == empty())
		{
			assert("");
		}

		return mEndNode->mPrev->mData;
	}

	iterator begin() const
	{
		iterator NewIter;
		NewIter.mNode = mBeginNode->mNext;
		return NewIter;
	}

	iterator end() const
	{
		iterator NewIter;
		NewIter.mNode = mEndNode;
		return NewIter;
	}

private:
	int mSize = 0;
	Node* mBeginNode = nullptr;
	Node* mEndNode = nullptr;

};

template<typename DataType>
void DisplayList(const MyList<DataType>& _List)
{
	LinkedListIteractor<DataType> StartIter = _List.begin();
	LinkedListIteractor<DataType> EndIter = _List.end();

	for (; StartIter!= EndIter;++StartIter)
	{
		std::cout << (*StartIter) << " \n";
	}

}