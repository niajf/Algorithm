#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;

  vector<ll> W(N);
  vector<ll> H(N);
  vector<ll> B(N);

  ll sum_weight = 0;
  ll sum_body = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> W[i] >> H[i] >> B[i];
    sum_weight += W[i];
    sum_body += B[i];
  }

  ll size = sum_weight / 2;
  // cout << size << endl;
  vector<vector<ll>> dp(N + 1, vector<ll>(size + 1));

  for (ll i = 0; i < dp[0].size(); i++)
    dp[0][i] = sum_body;

  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j <= size; ++j)
    {
      if (j >= W[i])
        dp[i + 1][j] = max(dp[i][j - W[i]] - B[i] + H[i], dp[i][j]);
      else
        dp[i + 1][j] = dp[i][j];
    }
  }

  // for (int i = 0; i <= N; i++)
  // {
  //   for (int j = 0; j < dp[i].size(); j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[N][size] << endl;

  return 0;
}