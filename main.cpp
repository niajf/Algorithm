#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int N;
  std::cin >> N;

  long long am;
  long long bm;

  std::cin >> am;
  for (int i = 0; i < N - 1; i++)
  {
    long long a;
    std::cin >> a;
    am = std::max(a, am);
  }

  std::cin >> bm;
  for (int i = 0; i < N - 1; i++)
  {
    long long b;
    std::cin >> b;
    bm = std::max(b, bm);
  }

  std::cout << am + bm << std::endl;

  return 0;
}