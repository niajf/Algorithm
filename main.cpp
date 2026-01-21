#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
  int N, K;
  std::cin >> N >> K;

  std::vector<int> R(N);
  for (auto &&elem : R)
    std::cin >> elem;

  std::vector<std::vector<int>> ans;

  std::vector<int> counter(N, 1);
  while ((counter.front() <= R.front()))
  {
    // for (auto const elem : counter)
    //   std::cout << elem << " ";
    // std::cout << std::endl;

    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += counter[i];

    if (sum % K == 0)
      ans.push_back(counter);

    counter[N - 1]++;

    for (int i = N - 1; i >= 0; i--)
    {
      if ((counter[i] > R[i]) && (i > 0))
      {
        counter[i - 1]++;
        counter[i] = 1;
      }
    }
  }

  std::sort(ans.begin(), ans.end());

  for (auto const vec : ans)
  {
    for (auto const elem : vec)
      std::cout << elem << " ";
    std::cout << std::endl;
  }

  return 0;
}