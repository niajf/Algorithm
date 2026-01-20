#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> H(N);
  for (auto &&enemy : H)
    std::cin >> enemy;

  std::vector<std::vector<int>> mod = {{1, 2, 3, 3}, {1, 2, 2, 2}, {1, 1, 1, 2}};
  long long T = 0;
  for (auto const enemy : H)
  {
    T += std::floor(enemy / 5) * 3;

    if (enemy % 5 != 0)
      T += mod[T % 3][enemy % 5 - 1];
  }

  std::cout << T << std::endl;

  return 0;
}