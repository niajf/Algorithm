#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;

  std::vector<std::string> table_prev(N);
  std::vector<std::string> table_new(N);

  for (int i = 0; i < N; i++)
    std::cin >> table_prev[i];

  std::copy(table_prev.begin(), table_prev.end(), table_new.begin());

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {

      int c = std::min({i + 1, j + 1, N - i, N - j});
      int ii = i;
      int jj = j;

      for (int k = 0; k < c % 4; k++)
      {
        int bi = N - 1 - jj, bj = ii;
        ii = bi;
        jj = bj;
      }

      table_new[i][j] = table_prev[ii][jj];
    }
  }

  for (auto const str : table_new)
    std::cout << str << std::endl;

  return 0;
}