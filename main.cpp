#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  // 高速化のおまじない
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  if (!(cin >> N))
    return 0;

  vector<long long> A(N);
  // 右側にある数の出現回数を管理するマップ
  map<long long, int> right_cnt;
  // 左側にある数の出現回数を管理するマップ
  map<long long, int> left_cnt;

  // 入力の受け取りと初期化（最初はすべて右側にあるとみなす）
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
    right_cnt[A[i]]++;
  }

  long long ans = 0;

  // 数列を左から走査し、現在の A[j] を「比率5」の真ん中の値として固定する
  for (int j = 0; j < N; ++j)
  {
    long long val_mid = A[j];

    // 現在地 j の要素は右側候補から除外
    right_cnt[val_mid]--;

    // 5で割り切れる場合のみ判定を行う
    if (val_mid % 5 == 0)
    {
      long long base = val_mid / 5;
      long long val_7 = base * 7; // 比率7の値 (A_i)
      long long val_3 = base * 3; // 比率3の値 (A_k)

      // マップは存在しないキーにアクセスすると0を返すため、そのまま計算可能

      // パターン1: j が一番右にある場合 (i < j, k < j)
      // A_i, A_k 共に左側にある個数を掛ける
      long long l7 = left_cnt[val_7];
      long long l3 = left_cnt[val_3];
      ans += l7 * l3;

      // パターン2: j が一番左にある場合 (j < i, j < k)
      // A_i, A_k 共に右側にある個数を掛ける
      long long r7 = right_cnt[val_7];
      long long r3 = right_cnt[val_3];
      ans += r7 * r3;
    }

    // 次のループのために、現在の要素を左側のカウントに加える
    left_cnt[val_mid]++;
  }

  cout << ans << endl;

  return 0;
}