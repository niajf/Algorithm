#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  long long ans = N;
  int i = 0, j = 1;
  while (i < N - 1)
  {
    int d = A[i + 1] - A[i];
    // std::cout << "start= " << i << " d= " << d << " ans= " << ans << std::endl;

    j = i + 1;
    while (j < N)
    {
      if (A[j] - A[j - 1] == d)
        ans += j - i;
      else
        break;

      j++;
    }
    i = j - 1;
  }

  std::cout << ans << std::endl;

  return 0;
}