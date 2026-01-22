#include <iostream>
#include <vector>
#include <set>

int main()
{
  int Q;
  std::cin >> Q;

  std::vector<int> A(1e6 + 1, 0);
  std::set<int> S;
  for (int q = 0; q < Q; q++)
  {
    int num;
    std::cin >> num;

    if (num == 1)
    {
      int x;
      std::cin >> x;
      A[x]++;
      S.insert(x);
    }

    else if (num == 2)
    {
      int x;
      std::cin >> x;
      A[x]--;

      if (A[x] == 0)
        S.erase(x);
    }

    else if (num == 3)
      std::cout << S.size() << std::endl;
  }

  return 0;
}