#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 桁数を取得する関数
int GetDigit(long long num)
{
  return to_string(num).length();
}

int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> A(N);
  // counts[len][remainder] = 個数
  // 桁数(len)ごとに、あまり(remainder)がいくつの数あるかを管理
  vector<map<int, int>> counts(11);

  // 10のべき乗 mod M を事前計算
  vector<long long> pow10(11);
  long long p = 1;
  for (int i = 0; i <= 10; i++)
  {
    pow10[i] = p % M;
    p = (p * 10) % M;
  }

  // データの読み込みと分類
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    int d = GetDigit(A[i]);
    int r = A[i] % M;
    // 「桁数d」で「あまりがr」である数の個数をカウント
    counts[d][r]++;
  }

  long long ans = 0;

  // A[i] を「前の数」としたとき、合う「後ろの数」を探す
  for (int i = 0; i < N; i++)
  {
    long long current_rem = A[i] % M;

    // 後ろに来る数の桁数 L (1桁〜10桁) を全探索
    for (int L = 1; L <= 10; L++)
    {
      // 条件: (A[i] * 10^L + A[j]) % M == 0
      // 変形: A[j] % M == -(A[i] * 10^L) % M

      // A[i] を L桁シフトした値のあまり
      long long term1 = (current_rem * pow10[L]) % M;

      // ペア成立に必要な A[j] のあまりを計算
      long long needed = (M - term1) % M;

      // 桁数が L で、あまりが needed になる数が存在すれば加算
      if (counts[L].count(needed))
      {
        ans += counts[L][needed];
      }
    }
  }

  cout << ans << endl;
  return 0;
}