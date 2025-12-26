#include <iostream>
#include <algorithm>
#include <map>

int main()
{
  int N;
  std::cin >> N;

  std::map<int, int> m;

  int ans = -1;
  for (int i = 0; i < N; i++)
  {
    int n;
    std::cin >> n;

    if (m.find(n) != m.end())
    {
      if (ans > (i - m[n] + 1) || (ans == -1))
        ans = i - m[n] + 1;
    }

    else
      m[n] = i;
  }

  std::cout << ans << std::endl;

  return 0;
}