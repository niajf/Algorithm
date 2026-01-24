#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
  long long N, M;
  std::cin >> N >> M;

  long long sum = 0;
  long long max = -1;
  std::vector<long long> A(N);

  for (int i = 0; i < N; i++)
  {
    long long n;
    std::cin >> n;
    sum += n;
    A[i] = n;

    if (max < n)
      max = n;
  }

  if (M >= sum)
  {
    std::cout << "infinite" << std::endl;
    return 0;
  }

  long start = 1;
  long end = max;
  long long x = 0;
  long long ans = 0;

  while (true)
  {
    x = start + (end - start) / 2;

    long long sum = 0;
    for (auto const elem : A)
    {
      if (x < elem)
        sum += x;
      else
        sum += elem;
    }

    if (sum == M)
    {
      ans = x;
      break;
    }

    else if (sum > M)
      end = x - 1;

    else
    {
      start = x + 1;
      ans = x;
    }

    if (start > end)
      break;
  }

  std::cout << ans << std::endl;

  return 0;
}