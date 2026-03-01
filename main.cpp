#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 十分に大きい値（到達不可能な状態の初期値）
const int INF = 1e9;

void solve()
{
  int H, W;
  cin >> H >> W;

  // 盤面を整数の配列（ビット列）として受け取る
  // 例: ".##." なら 2進数で 0110 (10進数で6) となる
  vector<int> grid(H, 0);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      char c;
      cin >> c;
      if (c == '#')
      {
        grid[i] |= (1 << j);
      }
    }
  }

  // 1行あたりの状態数は 2^W 通り
  int num_masks = 1 << W;

  // dp[mask] : 現在の行の状態を mask にしたときの最小操作回数
  vector<int> dp(num_masks, INF);

  // --- 0行目の初期化 ---
  for (int mask = 0; mask < num_masks; mask++)
  {
    // 条件1: 元の盤面で '.' の場所を '#' に変えることはできない
    // (元の盤面のサブセットでなければならない)
    if ((mask & grid[0]) != mask)
      continue;

    // コスト計算: 元は '#' だったが、mask では '.' に変えた数
    // 排他的論理和(^)で差分を取り、__builtin_popcountで立っているビットを数える
    dp[mask] = __builtin_popcount(grid[0] ^ mask);
  }

  // --- 1行目から H-1行目までの遷移 ---
  for (int i = 1; i < H; i++)
  {
    // 次の行用のDP配列
    vector<int> next_dp(num_masks, INF);

    // 現在の行の状態 (mask) を全探索
    for (int mask = 0; mask < num_masks; mask++)
    {
      // 条件1のチェック
      if ((mask & grid[i]) != mask)
        continue;

      // i行目を mask にするための操作回数
      int cost = __builtin_popcount(grid[i] ^ mask);

      // 直前の行の状態 (pmask) を全探索して遷移元を探す
      for (int pmask = 0; pmask < num_masks; pmask++)
      {
        if (dp[pmask] == INF)
          continue; // 到達不可能な状態はスキップ

        // 直前の行(pmask)と現在の行(mask)で「共通して '#' の場所」を抽出
        int common = mask & pmask;

        // 条件2: 共通の '#' が横に連続しているか判定（2x2ブロックの有無）
        // 右シフトして論理積を取ることで、横並びの1を一撃で判定できる
        if ((common & (common >> 1)) > 0)
          continue;

        // 遷移可能であれば、最小値を更新
        next_dp[mask] = min(next_dp[mask], dp[pmask] + cost);
      }
    }
    // DPテーブルを次の行のものに更新
    dp = next_dp;
  }

  // --- 答えの集計 ---
  // 最終行のすべての状態のうち、最小コストが求める答え
  int ans = INF;
  for (int mask = 0; mask < num_masks; mask++)
  {
    ans = min(ans, dp[mask]);
  }

  cout << ans << "\n";
}

int main()
{
  // 入出力の高速化（競技プログラミング用のおまじない）
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  if (cin >> T)
  {
    while (T--)
    {
      solve();
    }
  }
  return 0;
}