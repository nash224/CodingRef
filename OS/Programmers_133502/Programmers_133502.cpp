
#include <iostream>
#include <string>
#include <vector>
#include <array>

// 내가 선택한 문제인데 햄버거만 있어서 많이 아쉽다.
// 다음 문제는 자동으로 콜라에 관련된 문제 선택함 ^^

int solution(std::vector<int> _Ingredient);

int main()
{
	// 7~10
	// 5, 6, 11, 12
	int Answer = solution({ 2, 1, 1, 2, 3, 1, 2, 3, 1 });
	std::cout << Answer;
}

int solution(std::vector<int> _Ingredient)
{
	int answer = 0;

	// 햄버거 레시피
	const std::string RECIPE = "1231";

	// 왜 string을 선택했냐면, vector는 중간 삽입, 삭제의 시간이 오래 걸린다. << 배열을 초기화하고 다시 복사해야되기 때문
	// 사실 사용한 vector의 원소 값을 0으로 바뀌주고, 다음 햄버거 재료를 선택하는 로직을 짰지만,
	// 30분 넘게 삽질하고 포기했다.
	std::string StrIngredient;
	StrIngredient.reserve(_Ingredient.size());

	// 재료를 전부 string으로 교체
	for (int Elem : _Ingredient)
	{
		StrIngredient.push_back(static_cast<char>(Elem) + '0');
	}

	size_t Offset = 0;

	while (true)
	{
		// 레시피에 해당되는 부분이 존재하면 원소를 삭제하고 
		// 재료가 소모되면서 앞과 뒤에 연결된 재료로 햄버거를 만들 수 있음으로 Offset을 미룬다.
		Offset = StrIngredient.find(RECIPE, Offset); 
		if (std::string::npos == Offset)
		{
			break;
		}

		// 찾으면 원소를 빼고 offset 초기화
		StrIngredient.erase(Offset, 4);
		Offset = std::max(static_cast<int>(Offset) - 3, 0);
		++answer;
	}

	return answer;
}