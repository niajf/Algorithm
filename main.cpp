#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <numeric>

// Combination  nCr ----------
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
// ------------------------------

vector<pair<int, string>> solve(int r, vector<int> const &scores)
{
  string alphabets = "ABCDE";
  vector<int> index = {0, 1, 2, 3, 4};

  vector<pair<int, string>> res;

  vector<vector<int>> comb = combination(index, r);
  for (const auto vec : comb)
  {
    string str = "";
    int score = 0;
    for (const auto elem : vec)
    {
      str += alphabets[elem];
      score += scores[elem];
    }
    res.push_back({score, str});
  }

  return res;
}

int main()
{
  vector<int> scores(5);
  vector<pair<int, string>> res;

  for (auto &&elem : scores)
    std::cin >> elem;

  for (int i = 5; i >= 0; i--)
  {
    auto vec = solve(i, scores);
    for (const auto p : vec)
      res.push_back(p);
  }

  sort(res.begin(), res.end(), [&](pair<int, string> i, pair<int, string> j) -> bool
       {
        if (i.first != j.first) return i.first > j.first;
        return i.second < j.second; });

  for (int i = 0; i < res.size() - 1; i++)
    std::cout << res[i].second << std::endl;
}