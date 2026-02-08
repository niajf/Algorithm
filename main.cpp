#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M), C(M + 1);

  for (auto &&a : A)
    cin >> a;

  ll b_sum = 0;
  for (auto &&b : B)
  {
    cin >> b;
    b_sum += b;
  }

  sort(B.begin(), B.end());

  ll sum = 0;
  C[0] = -b_sum;
  for (int i = 0; i < M; i++)
  {
    sum += B[M - i - 1];
    C[i + 1] = -b_sum + 2 * sum;
  }

  ll ans = 0;
  for (auto const a : A)
  {
    // 自身より大きいbの数
    ll cnt = 0;
    auto itr = upper_bound(B.begin(), B.end(), a);
    cnt = B.end() - itr;
    ll term1 = (a % MOD) * ((M - 2 * cnt) % MOD) % MOD;
    ll term2 = C[cnt] % MOD;
    ans = (ans + term1 + term2) % MOD;
  }

  ans = (ans + MOD) % MOD;
  cout << ans << endl;

  return 0;
}
