#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

template <class T>
void dfs_combination(vector<T> &arr, int idx, int r, vector<T> &pattern, vector<vector<T>> &result)
{
  if (r == 0)
  {
    result.push_back(pattern);
    return;
  }
  if ((idx + r) > arr.size())
  {
    return;
  }

  // select
  pattern.push_back(arr[idx]);
  dfs_combination(arr, idx + 1, r - 1, pattern, result);
  pattern.pop_back();
  // not select
  dfs_combination(arr, idx + 1, r, pattern, result);
}

template <class T>
vector<vector<T>> combination(vector<T> &arr, int r)
{
  if (arr.size() < r)
  {
    printf("combination ERROR: r is larger than arr.size()\n");
    exit(1);
  }

  vector<T> pattern;
  vector<vector<T>> result;
  dfs_combination(arr, 0, r, pattern, result);
  return result;
}

int main()
{

  int N;
  long long ans = 0, whole_sum = 0;
  cin >> N;

  vector<int> K(N);

  for (auto &&elem : K)
  {
    cin >> elem;
    whole_sum += elem;
  }

  sort(K.begin(), K.end());
  ans = whole_sum;

  // int R;
  // long long sum = 0;
  // for (int i = 0; i < N; i++)
  // {
  //   sum += K[i];
  //   if (sum > whole_sum / 2)
  //   {
  //     R = i;
  //     break;
  //   }
  // }

  for (int r = 1; r <= (N / 2); r++)
  {
    vector<vector<int>> comb = combination(K, r);

    for (auto const arr : comb)
    {
      long long sum = 0;
      for (auto const elem : arr)
        sum += elem;

      ans = min(ans, max(whole_sum - sum, sum));
    }
  }
  cout << ans << endl;
  return 0;
}