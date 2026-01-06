
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  int N, K;
  std::cin >> N >> K;

  std::string data;
  std::cin >> data;

  std::vector<int> L;
  std::vector<int> R;

  bool isOne = false;
  for (int i = 0; i < N; i++)
  {
    if (data[i] == '1')
    {
      if (!isOne)
      {
        L.push_back(i);
        isOne = true;
      }
    }

    else
    {
      if (isOne)
      {
        R.push_back(i - 1);
        isOne = false;
      }
    }
  }

  if (L.size() != R.size())
    R.push_back(N - 1);

  // for (auto const elem : L)
  //   std::cout << elem << ", ";
  // std::cout << std::endl;

  // for (auto const elem : R)
  //   std::cout << elem << ", ";
  // std::cout << std::endl;

  for (int i = L[K - 1]; i <= R[K - 1]; i++)
    data[i] = '0';

  for (int i = R[K - 2] + 1; i <= R[K - 2] + 1 + (R[K - 1] - L[K - 1]); i++)
    data[i] = '1';

  std::cout << data << std::endl;

  return 0;
}