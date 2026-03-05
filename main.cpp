#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<ll, ll> direction(char c)
{
  pair<ll, ll> dire = {0, 0};

  switch (c)
  {
  case 'U':
    dire = {-1, 0};
    break;

  case 'R':
    dire = {0, 1};
    break;

  case 'D':
    dire = {1, 0};
    break;

  case 'L':
    dire = {0, -1};
    break;
  }

  return dire;
}

int main()
{
  ll N, M, L;
  pair<ll, ll> t, a;

  cin >> t.first >> t.second >> a.first >> a.second;
  cin >> N >> M >> L;

  vector<pair<char, ll>> S(M), T(L);
  for (int i = 0; i < M; i++)
    cin >> S[i].first >> S[i].second;

  for (int i = 0; i < L; i++)
    cin >> T[i].first >> T[i].second;

  int si = 0, ti = 0;
  int s_rem = S[0].second, t_rem = T[0].second;

  ll ans = 0;
  for (int i = 0; i < M + L - 1; i++)
  {
    ll r0 = t.first - a.first;
    ll c0 = t.second - a.second;

    ll k = min(s_rem, t_rem);

    ll delta_r = direction(S[si].first).first - direction(T[ti].first).first;
    ll delta_c = direction(S[si].first).second - direction(T[ti].first).second;

    // cout << s_rem << ", " << t_rem << " : " << k << " : " << r0 << ", " << c0 << " : " << delta_r << ", " << delta_c << endl;

    if ((delta_r == 0) && (delta_c == 0))
    {

      if ((r0 == 0) && (c0 == 0))
      {
        ans += k;
      }
    }
    else if (delta_r == 0)
    {
      if (c0 % delta_c == 0)
      {
        ll time = -c0 / delta_c;
        if ((0 < time) && (time <= k) && (r0 == 0))
          ans++;
      }
    }
    else if (delta_c == 0)
    {
      if (r0 % delta_r == 0)
      {
        ll time = -r0 / delta_r;
        if ((0 < time) && (time <= k) && (c0 == 0))
          ans++;
      }
    }
    else
    {
      if ((c0 % delta_c == 0) && (r0 % delta_r == 0))
      {
        ll time_r = -r0 / delta_r;
        ll time_c = -c0 / delta_c;
        if ((time_r == time_c) && (0 < time_r) && (time_r <= k))
          ans++;
      }
    }

    s_rem -= k;
    t_rem -= k;

    t.first += k * direction(S[si].first).first;
    t.second += k * direction(S[si].first).second;
    a.first += k * direction(T[ti].first).first;
    a.second += k * direction(T[ti].first).second;

    if ((s_rem == 0) && (si + 1 < M))
    {
      si++;
      s_rem = S[si].second;
    }

    if ((t_rem == 0) && (ti + 1 < L))
    {
      ti++;
      t_rem = T[ti].second;
    }
  }

  cout << ans << endl;

  return 0;
}