#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{

  std::string S, T;
  std::cin >> S >> T;

  std::vector<std::string> X;

  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] > T[i])
    {
      S[i] = T[i];
      X.push_back(S);
    }
  }

  for (int i = S.size(); i >= 0; i--)
  {
    if (S[i] < T[i])
    {
      S[i] = T[i];
      X.push_back(S);
    }
  }

  // std::sort(X.begin(), X.end());

  std::cout << X.size() << std::endl;
  for (auto const str : X)
    std::cout << str << std::endl;

  return 0;
}