#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
  ll N, M;
  cin >> N >> M;

  vector<ll> X(N);
  for (ll i = 0; i < N; i++)
    cin >> X[i];
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());

  // for (int i = 0; i < X.size(); i++)
  //   cout << X[i] << " ";
  // cout << endl;

  if ((M == N) || (X.size() <= 1))
  {
    cout << 0 << endl;
    return 0;
  }
  else if (M == 1)
  {
    cout << X[X.size() - 1] - X[0] << endl;
    return 0;
  }

  vector<pair<ll, ll>> D(X.size() - 1);
  for (ll i = 1; i < X.size(); i++)
  {
    D[i - 1] = {X[i] - X[i - 1], i};
    // cout << D[i - 1].first << " " << D[i - 1].second << endl;
  }
  // cout << endl;
  sort(D.rbegin(), D.rend());

  // for (int i = 0; i < X.size() - 1; i++)
  //   cout << D[i].first << " " << D[i].second << endl;
  // cout << endl;

  vector<ll> pos(M);
  pos[M - 1] = X.size() - 1;
  for (ll i = 0; i < M - 1; i++)
  {
    pos[i] = D[i].second;
    // cout << pos[i] << endl;
  }
  // cout << pos[M - 1] << endl;
  sort(pos.begin(), pos.end());

  ll s = 0, e;
  ll ans = 0;
  for (ll i = 0; i < M; i++)
  {
    i < M - 1 ? e = pos[i] - 1 : e = pos[i];

    // cout << X[s] << " " << X[e] << endl;
    ans += X[e] - X[s];
    s = pos[i];
  }

  cout << ans << endl;

  return 0;
}