// Programmers_176962.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

std::vector<std::string> solution(std::vector<std::vector<std::string>> plans);

struct FPlan
{
	std::string strName;
	int iStartTime = 0;
	int iDuration = 0;
};

int TimeToInt(const std::string& _StrTime)
{
	const int TIME_INT = std::stoi(_StrTime.substr(0, 2)) * 60 + std::stoi(_StrTime.substr(3, 2));
	return TIME_INT;
}

int MaxINT()
{
	const int MAXINT = static_cast<int>(static_cast<unsigned int>(-1) / 2);
	return MAXINT;
}

// 1. 자료를 정렬 후, queue에 삽입
//		-> Plan구조체에서 시작 시간을 오름차순으로 정렬
//		-> Vector에서 일괄 정렬하고 queue에 순차적으로 삽입
// 2. 필요할때마다 queue에서 빼옴
//		-> 작업이 시작될때 Plan을 빼옴
// 3. 다음 작업이 시작되면 기존에 있는 일을 stack에 보관
//		-> 만약 작업시간이 남으면 기존에 했던 작업을 시난 시간만큼 소모하고 Stack에 보관
//		-> Remain TAsk Time = Task[1] - Task[0]
// 4. 일 없을때 stack에서 빼옴
// 5. 끝난 작업을 순서대로 반환

class CPlanner
{
public:
	CPlanner(const std::vector<std::vector<std::string>>& plans)
	{
		m_Plans.reserve(plans.size());

		const int NUMBER_OF_ELEMENT = 3;
		for (const std::vector<std::string>& plan : plans)
		{
			FPlan& PlanRef = m_Plans.emplace_back();
			
			for (int i = 0; i < NUMBER_OF_ELEMENT; i++)
			{
				PlanRef.strName = plan[0];
				PlanRef.iStartTime = TimeToInt(plan[1]);
				PlanRef.iDuration = std::stoi(plan[2]);
			}
		}

		std::sort(m_Plans.begin(), m_Plans.end(), [](const FPlan& _Left, const FPlan& _Right)
			{
				return _Left.iStartTime < _Right.iStartTime;
			});
	}

	const std::vector<std::string>& Run()
	{
		const int LIST_SIZE = static_cast<int>(m_Plans.size());
		const int LAST_TASK_NUMBER = LIST_SIZE - 1;

		int Offset = 0;

		for (int i = 0; i < LAST_TASK_NUMBER; i++)
		{
			FPlan& CurPlan = m_Plans[i];
			FPlan& NextPlan = m_Plans[i + 1];

			const int END_TIME = CurPlan.iStartTime + CurPlan.iDuration;
			const int NEXT_START_TIME = NextPlan.iStartTime;
			if (NEXT_START_TIME < END_TIME)
			{
				CurPlan.iDuration = END_TIME - NEXT_START_TIME;
				m_Blocked.push(&CurPlan);
			}
			else if (NEXT_START_TIME == END_TIME)
			{
				m_Done.push_back(CurPlan.strName);
			}
			else if (END_TIME < NEXT_START_TIME)
			{
				m_Done.push_back(CurPlan.strName);

				int RemainTime = NEXT_START_TIME - END_TIME;
				DoRemainTask(RemainTime);
			}

			bool IsLast = (LAST_TASK_NUMBER == (i + 1));
			if (true == IsLast)
			{
				m_Blocked.push(&NextPlan);
			}
		}

		while (false == m_Blocked.empty())
		{
			m_Done.push_back(m_Blocked.top()->strName);
			m_Blocked.pop();
		}

		return m_Done;
	}

private:
	void DoRemainTask(int _RemainTime)
	{
		while (false == m_Blocked.empty())
		{
			FPlan* pDelayPlan = m_Blocked.top();
			m_Blocked.pop();

			if (pDelayPlan->iDuration < _RemainTime)
			{
				_RemainTime -= pDelayPlan->iDuration;
				m_Done.push_back(pDelayPlan->strName);
				continue;
			}
			else if (pDelayPlan->iDuration == _RemainTime)
			{
				m_Done.push_back(pDelayPlan->strName);
				break;
			}
			else
			{
				pDelayPlan->iDuration -= _RemainTime;
				m_Blocked.push(pDelayPlan);
				break;
			}
		}
	}

private:
	std::vector<FPlan> m_Plans;
	std::stack<FPlan*> m_Blocked;
	std::vector<std::string> m_Done;

};

int main()
{
	solution({ { "korean", "11:40", "30" }, {"english", "12:10", "20"}, { "math", "12:30", "40" }});
    std::cout << "Hello World!\n";
}



std::vector<std::string> solution(std::vector<std::vector<std::string>> plans)
{
	CPlanner NewPlanner(plans);
	const std::vector<std::string>& Answer = NewPlanner.Run();
	return Answer;
}
