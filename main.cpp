#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
  unsigned long long N;
  int M;

  std::cin >> N >> M;
  std::map<std::pair<int, int>, int> map;

  std::vector<int> offset_i = {-2, -1, 1, 2, 2, 1, -1, -2};
  std::vector<int> offset_j = {1, 2, 2, 1, -1, -2, -2, -1};

  for (int m = 0; m < M; m++)
  {
    int i, j;
    std::cin >> i >> j;

    map[{i, j}] = 1;

    for (int k = 0; k < 8; k++)
    {
      if ((1 <= i + offset_i[k]) && (i + offset_i[k] <= N) && (1 <= j + offset_j[k]) && (j + offset_j[k] <= N))
        map[{i + offset_i[k], j + offset_j[k]}] = 1;
    }
  }

  unsigned long long ans = N * N;
  ans -= map.size();

  // std::cout << map.size() << std::endl;
  // std::cout << N * N << std::endl;
  std::cout << ans << std::endl;

  return 0;
}