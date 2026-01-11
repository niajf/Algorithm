#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int T;
  std::cin >> T;

  while (T)
  {
    int N, W;
    std::cin >> N >> W;

    std::vector<long long> A(2 * W, 0);
    for (int i = 0; i < N; i++)
    {
      int num;
      std::cin >> num;

      A[i % (2 * W)] += num;
    }

    // for (auto const elem : A)
    //   std::cout << elem << " ";
    // std::cout << std::endl;

    int s, e;
    long long ans, sum = 0;
    s = 1;
    e = W;

    for (int i = 0; i < W; i++)
      sum += A[i];
    ans = sum;
    // std::cout << sum << " ";

    for (int i = 0; i < 2 * W; i++)
    {

      sum -= A[s - 1];
      sum += A[e];
      // std::cout << sum << " ";
      ans = std::min(ans, sum);

      s++;
      e++;

      if (e >= 2 * W)
        e -= 2 * W;
    }
    // std::cout << std::endl;

    std::cout << ans << std::endl;
    T--;
  }

  return 0;
}