#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  int N, Q;
  cin >> N;

  int maxNum = 0;
  vector<int> downSum(N, 0);
  vector<vector<int>> table(N, vector<int>(3, 0));
  for (int i = 0; i < N; i++)
  {
    cin >> table[i][0] >> table[i][1] >> table[i][2];
    maxNum = max(table[i][0] + table[i][1], maxNum);
    (0 < i) ? (downSum[i] = table[i][2] + downSum[i - 1]) : (downSum[i] = table[i][2]);
  }

  vector<vector<int>> dp(N, vector<int>(maxNum + 1, 0));
  for (int i = 0; i <= maxNum; i++)
  {
    if (i <= table[N - 1][0])
      dp[N - 1][i] = i + table[N - 1][1];
    else
      dp[N - 1][i] = max(i - table[N - 1][2], 0);
  }

  for (int i = N - 2; i >= 0; i--)
  {
    for (int j = 0; j <= maxNum; j++)
    {
      if (j <= table[i][0])
      {
        dp[i][j] = dp[i + 1][j + table[i][1]];
      }
      else
      {
        dp[i][j] = dp[i + 1][max(j - table[i][2], 0)];
      }
    }
  }

  // for (int i = 0; i < N; i++)
  //   cout << downSum[i] << " ";
  // cout << endl;
  // cout << maxNum << endl;

  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    int X;
    cin >> X;

    if (X > maxNum)
    {
      auto iter = lower_bound(downSum.begin(), downSum.end(), X - maxNum);

      if (iter == downSum.end())
        X -= downSum[N - 1];
      else
        X = max(X - *iter, 0);

      if (iter - downSum.begin() + 1 < N)
        cout << dp[iter - downSum.begin() + 1][X] << endl;
      else
      {
        cout << X << endl;
      }
    }
    else
      cout << dp[0][X] << endl;
  }

  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j <= maxNum; j++)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }

  return 0;
}