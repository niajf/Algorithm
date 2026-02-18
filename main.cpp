#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, M, K;
    string S;
    cin >> N >> M >> K >> S;

    vector<vector<int>> G(N, vector<int>());
    for (int m = 0; m < M; m++)
    {
      int u, v;
      cin >> u >> v;
      G[u - 1].push_back(v - 1);
    }

    vector<bool> dp(N);
    for (int i = 0; i < N; i++)
    {
      if (S[i] == 'A')
        dp[i] = true;
      else
        dp[i] = false;
    }

    for (int k = 0; k < K; k++)
    {
      // for (int i = 0; i < N; i++)
      //   cout << dp[i] << " ";
      // cout << "\n";

      {
        vector<bool> ep(N, true);
        for (int i = 0; i < N; i++)
        {
          for (auto j : G[i])
          {
            if (!dp[j])
              ep[i] = false;
          }
        }
        copy(ep.begin(), ep.end(), dp.begin());
      }

      // for (int i = 0; i < N; i++)
      //   cout << dp[i] << " ";
      // cout << "\n";
      {
        vector<bool> ep(N, false);
        for (int i = 0; i < N; i++)
        {
          for (auto j : G[i])
          {
            if (dp[j])
              ep[i] = true;
          }
        }
        copy(ep.begin(), ep.end(), dp.begin());
      }
    }

    // for (int i = 0; i < N; i++)
    //   cout << dp[i] << " ";
    // cout << "\n";

    cout << ((dp[0]) ? ("Alice") : ("Bob")) << "\n";
  }
}