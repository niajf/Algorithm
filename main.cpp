#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long int ll;

ll f(ll a, ll b)
{
  for (int i = 0; i < to_string(b).size(); i++)
    a *= 10;

  return a + b;
}

ll g(ll x)
{
  ll y = sqrt(x);
  while (y * y > x)
    y--;
  while ((y + 1) * (y + 1) <= x)
    y++;
  return y;
}

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; t++)
  {
    ll ans = 0;
    ll C, D;
    cin >> C >> D;

    ll xmin = 1, xmax = 9, cshift = 10;
    while (xmin <= C + D)
    {
      ll l = max(xmin, C + 1);
      ll r = min(xmax, C + D);
      if (l <= r)
      {
        ll vl = C * cshift + l;
        ll vr = C * cshift + r;
        ans += (g(vr) - g(vl - 1));
      }
      xmin = xmin * 10;
      xmax = (xmax + 1) * 10 - 1;
      cshift *= 10;
    }

    cout << ans << endl;
  }

  return 0;
}