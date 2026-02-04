#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * f(M, A): M 以下の整数のうち、リスト A に含まれないものの個数を返す
 * リスト A はあらかじめ昇順にソートされている必要がある
 */
long long f(long long M, const vector<long long> &A)
{
  // std::upper_bound で M 以下の要素数をカウント
  long long count_in_A = upper_bound(A.begin(), A.end(), M) - A.begin();
  return M - count_in_A;
}

int main()
{
  // 高速入出力の設定
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  if (!(cin >> N >> Q))
    return 0;

  vector<long long> A(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
  }

  // 二分探索のために昇順ソート
  sort(A.begin(), A.end());

  for (int j = 0; j < Q; ++j)
  {
    long long X, Y;
    cin >> X >> Y;

    // X-1 以下に含まれない数がいくつあるか
    long long offset = f(X - 1, A);
    // 全体として小さい方から「offset + Y」番目の含まれない数を探す
    long long target_rank = offset + Y;

    // 二分探索の範囲設定
    // X, Y が最大 10^9 なので、答えは最大 2*10^9 程度になる
    long long low = 1, high = 2000000000LL;
    long long ans = high;

    while (low <= high)
    {
      long long mid = low + (high - low) / 2;
      if (f(mid, A) >= target_rank)
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}