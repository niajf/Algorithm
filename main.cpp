#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main()
{

  int N;
  std::string S, T;

  std::cin >> N >> S >> T;

  S += "..";
  T += "..";

  std::map<std::string, int> dp;
  std::queue<std::string> que;

  dp[S] = 0;
  que.push(S);

  while (!que.empty())
  {
    auto str = que.front();
    que.pop();

    int emp = 0;
    for (int i = 0; i < S.size(); i++)
    {
      if (str[i] == '.')
      {
        emp = i;
        break;
      }
    }

    for (int i = 0; i + 1 < S.size(); i++)
    {
      if (str[i] == '.' || str[i + 1] == '.')
        continue;

      std::string str2 = str;
      std::swap(str2[i], str2[emp]);
      std::swap(str2[i + 1], str2[emp + 1]);
      if (!dp.count(str2))
      {
        dp[str2] = dp[str] + 1;
        que.push(str2);
      }
    }
  }

  if (dp.count(T))
    std::cout << dp[T] << std::endl;

  else
    std::cout << -1 << std::endl;

  return 0;
}