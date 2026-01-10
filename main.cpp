#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  std::vector<int> B(N - 1);

  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  for (int i = 0; i < N - 1; i++)
    std::cin >> B[i];

  std::sort(A.rbegin(), A.rend());
  std::sort(B.begin(), B.end());

  int ans = -1;
  auto pos = B.end();

  for (auto const elem : A)
  {
    auto iter = std::lower_bound(B.begin(), pos, elem);

    if (iter != pos)
      --pos;

    else
      ans = elem;
  }

  if (pos == B.begin())
    std::cout << ans << std::endl;
  else
    std::cout << -1 << std::endl;

  return 0;
}