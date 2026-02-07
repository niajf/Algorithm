#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N = 5;

  vector<pair<int, int>> items = {{120, 8}, {150, 10}, {140, 7}, {110, 6}, {100, 7}};
  vector<vector<int>> dp(N + 1, vector<int>(30 + 1));

  for (int i = 0; i < dp[0].size(); i++)
    dp[0][i] = 0;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= 30; ++j)
    {
      if (j >= items[i].second)
        dp[i + 1][j] = max(dp[i][j - items[i].second] + items[i].first, dp[i][j]);
      else
        dp[i + 1][j] = dp[i][j];
    }
  }

  cout << dp[N][30] << endl;

  return 0;
}
