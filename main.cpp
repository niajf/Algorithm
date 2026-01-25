#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
  long long N, K, X;
  std::cin >> N >> K >> X;

  std::vector<long long> A(N);
  for (auto &&elem : A)
    std::cin >> elem;

  std::sort(A.rbegin(), A.rend());

  long long sum = 0;
  long long ans = -1;
  for (long long i = N - K; i < N; i++)
  {
    sum += A[i];
    if (sum >= X)
    {
      ans = i + 1;
      break;
    }
  }

  std::cout << ans << std ::endl;

  return 0;
}