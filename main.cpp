#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  long long N, T;
  string S;

  cin >> N >> T >> S;

  vector<int> pr, nw;
  vector<pair<long long, int>> pos(N);

  for (int i = 0; i < N; i++)
  {
    long long x;
    cin >> x;
    pos[i].first = x;
    pos[i].second = S[i] - '0';
  }

  sort(pos.begin(), pos.end());

  for (auto const elem : pos)
  {
    if (elem.second == 1)
      pr.push_back(0);

    else if (elem.second == 0)
    {
      for (auto &&p : pr)
        p++;
    }
  }

  for (auto &&elem : pos)
  {
    if (elem.second == 0)
      elem.first -= T;
    else if (elem.second == 1)
      elem.first += T;
  }

  sort(pos.begin(), pos.end());

  for (auto const elem : pos)
  {
    if (elem.second == 1)
      nw.push_back(0);

    else if (elem.second == 0)
    {
      for (auto &&p : nw)
        p++;
    }
  }

  // for (auto elem : pos)
  //   cout << elem.first << " " << elem.second << endl;

  // for (auto const elem : pr)
  //   cout << elem << " ";
  // cout << endl;

  // for (auto const elem : nw)
  //   cout << elem << " ";
  // cout << endl;

  long long ans = 0;
  for (int i = 0; i < pr.size(); i++)
  {
    ans += pr[i];
    ans -= nw[i];
  }

  cout << ans << endl;

  return 0;
}
