#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

int main()
{
  int N, M;
  std::cin >> N >> M;

  std::map<int, int> edges;

  for (int i = 1; i <= N; i++)
    edges[i] = 0;

  for (int i = 0; i < M; i++)
  {
    int s, e;
    std::cin >> s >> e;

    edges[s]++;
    edges[e]++;
  }

  // for (auto const elem : edges)
  //   std::cout << elem.second << " ";
  // std::cout << std::endl;

  for (int i = 1; i <= N; i++)
  {
    long long a = 1;
    for (int j = 0; j < 3; j++)
      a *= (N - 1 - edges[i] - j);

    std::cout << a / 6 << " ";
  }
  std::cout << std::endl;

  return 0;
}