#include <iostream>
#include <map>
#include <vector>

int main()
{
  int N;
  std::cin >> N;

  std::map<int, int> M;
  std::vector<int> B;

  for (int i = 0; i < N; i++)
  {
    int num;
    std::cin >> num;

    if (M.find(num) == M.end())
    {
      B.push_back(-1);
      M[num] = i;
    }
    else
    {
      B.push_back(M[num] + 1);
      M[num] = i;
    }
  }

  for (auto const elem : B)
    std::cout << elem << " ";
  std::cout << std::endl;

  return 0;
}