// BJ_15649.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

void backtrack(int n, int m, int depth, std::vector<int>& path, std::vector<bool>& used, std::vector<std::vector<int>>& results) {
	if (depth == m) {
		results.push_back(path);
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			used[i] = true;
			path.push_back(i);
			backtrack(n, m, depth + 1, path, used, results);
			path.pop_back();
			used[i] = false;
		}
	}
}

std::vector<std::vector<int>> solve(int n, int m) {
	std::vector<bool> used(n + 1, false);
	std::vector<std::vector<int>> results;
	std::vector<int> path;
	backtrack(n, m, 0, path, used, results);
	return results;
}

int main() {
	int n = 4, m = 2;
	std::vector<std::vector<int>> result = solve(n, m);
	for (const auto& seq : result) {
		for (int num : seq) {
			std::cout << num << " ";
		}
		std::cout << "\n";
	}
	return 0;
}