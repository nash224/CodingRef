
#include <iostream>
#include <string>
#include <vector>
#include <array>

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

	const std::string RECIPE = "1231";

	std::string StrIngredient;
	StrIngredient.reserve(_Ingredient.size());

	for (int Elem : _Ingredient)
	{
		StrIngredient.push_back(static_cast<char>(Elem) + '0');
	}

	size_t Offset = 0;

	while (true)
	{
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