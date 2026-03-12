#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
  ll N, M;
  cin >> N >> M;

  vector<tuple<ll, ll, ll>> table(M);
  for (int i = 0; i < M; i++)
  {
    ll a, b;
    cin >> a >> b;

    ll diff = a - b;
    table[i] = {diff, a, b};
  }

  sort(table.begin(), table.end());

  ll ans = 0;
  for (int idx = 0; idx < M; idx++)
  {
    auto [diff, a, b] = table[idx];
    if (N >= a)
    {
      ll cnt = (N - a) / diff;
      ans += cnt + 1;
      N -= (cnt + 1) * diff;
    }
  }

  cout << ans << endl;

  return 0;
}