
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int ll;
int main()
{
  ll N;
  int M;
  std::cin >> N >> M;

  std::vector<std::pair<int, int>> XA(M);
  std::vector<int> C(M, 0);

  for (int i = 0; i < M; i++)
    std::cin >> XA[i].first;

  for (int i = 0; i < M; i++)
    std::cin >> XA[i].second;

  std::sort(XA.begin(), XA.end());

  ll ans = 0;
  ll sum = 0;
  for (int i = 0; i < M; i++)
  {
    if (sum < XA[i].first - 1)
    {
      std::cout << -1 << std::endl;
      return 0;
    }

    sum += XA[i].second;
    ans += XA[i].second * XA[i].first;
  }

  if (sum != N)
  {
    std::cout << -1 << std::endl;
    return 0;
  }
  else
    std::cout << N * (N + 1) / 2 - ans << std::endl;

  return 0;
}