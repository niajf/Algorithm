#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;
using ll = long long;

int main()
{
  int N;
  cin >> N;

  map<int, ll> M;
  M[0] = 0;

  ll total_length = 0;
  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;

    M[x] = 0;
    auto iter = M.find(x);
    auto prev_it = prev(iter);
    auto next_it = next(iter);

    // 初期化
    int prev_length, next_length;
    prev_length = iter->first - prev_it->first;

    next_length = 1e9;
    if (next_it != M.end())
      next_length = next_it->first - iter->first;

    // cout << "prev length : " << prev_length << endl;
    // cout << "next length : " << next_length << endl;

    // 距離の計算
    iter->second = min(prev_length, next_length);
    total_length += iter->second;

    // 距離の更新
    if (i == 0)
    {
      prev_it->second = prev_length;
      total_length += prev_it->second;
    }
    else if (prev_it->second > prev_length)
    {
      total_length -= prev_it->second;
      prev_it->second = prev_length;
      total_length += prev_it->second;
    }

    if ((next_it != M.end()) && (next_it->second > next_length))
    {
      total_length -= next_it->second;
      next_it->second = next_length;
      total_length += next_it->second;
    }

    cout << total_length << endl;
  }

  return 0;
}