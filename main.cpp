#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  long long N, X, Y;
  std::cin >> N >> X >> Y;

  std::vector<long long> A(N);
  std::vector<long long> B(N);

  for (auto &&a : A)
    std::cin >> a;

  for (auto &&b : B)
    std::cin >> b;

  std::sort(A.rbegin(), A.rend());
  std::sort(B.rbegin(), B.rend());

  int ans = N;
  long long a_sum = 0, b_sum = 0;
  for (int i = 0; i < N; i++)
  {
    a_sum += A[i];
    b_sum += B[i];

    if (a_sum > X)
    {
      ans = i + 1;
      break;
    }

    else if (b_sum > Y)
    {
      ans = i + 1;
      break;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}