// Programmers_132266.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

class CGraphNode
{
public:
	void Link(CGraphNode* _pNode)
	{
		if (nullptr == _pNode)
		{
			// Error
			return;
		}

		mEdges.push_back(_pNode);
	}

private:
	int mID;
	std::vector<CGraphNode*> mEdges;

};

class CGraph
{
	using Node = CGraphNode;
public:
	void LinkNode(int _Left, int _Right)
	{
		const int NodeSize = static_cast<int>(mNodes.size());
		if (NodeSize <= _Left || NodeSize <= _Right)
		{
			// Error
			return;
		}

		Node& LeftNode = mNodes.at(_Left);
		Node& RightNode = mNodes.at(_Right);
		LeftNode.Link(&RightNode);
		LeftNode.Link(&LeftNode);
	}

private:
	std::vector<Node> mNodes;

};

std::vector<int> solution(int n, std::vector<std::vector<int>> roads, std::vector<int> sources, int destination)
{
	std::vector<int> answer;

	CGraph NewGraph;

	return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}