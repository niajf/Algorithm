#include <iostream>
#include <vector>

int main()
{
  int N;
  std::cin >> N;

  std::vector<std::pair<int, int>> stack = {{0, 0}};

  for (int i = 0; i < N; i++)
  {
    int n;
    std::cin >> n;

    if (stack.back().first == n)
    {
      stack.back().second++;

      if (stack.back().second >= 4)
        stack.pop_back();
    }
    else
    {
      stack.push_back({n, 1});
    }
  }

  int ans = 0;
  for (const auto &p : stack)
    ans += p.second;

  std::cout << ans << std::endl;

  return 0;
}