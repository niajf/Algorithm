
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> count(N + 1, 0);
  std::set<int> s;

  int upper = std::sqrt(N);

  for (int i = 1; i <= upper; i++)
  {
    for (int j = i + 1; j <= upper; j++)
    {
      int num = i * i + j * j;
      if (num <= N)
        count[num]++;

      else
        break;
    }
  }

  std::vector<int> res;
  for (int i = 0; i < count.size(); i++)
  {
    if (count[i] == 1)
      res.push_back(i);
  }

  std::cout << res.size() << std::endl;
  for (auto const elem : res)
    std::cout << elem << " ";
  std::cout << std::endl;

  return 0;
}