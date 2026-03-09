#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
  int N;
  string T;
  cin >> N >> T;

  ll dp0 = 0, dp1 = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (T[i] == '0')
    {
      ll ndp0, ndp1;
      ndp0 = dp1;
      ndp1 = dp0 + 1;
      dp0 = ndp0;
      dp1 = ndp1;
    }
    else
    {
      ll ndp0, ndp1;
      ndp0 = dp0 + 1;
      ndp1 = dp1;
      dp0 = ndp0;
      dp1 = ndp1;
    }

    ans += dp0;
  }

  cout << ans << endl;

  return 0;
}