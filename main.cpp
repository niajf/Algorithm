#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  // 高速化のための設定
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N, M, C;
  if (!(cin >> N >> M >> C))
    return 0;

  // 各座標に何人いるかを集計 (mapを使うことで自動的にソートされます)
  map<long long, long long> counts;
  for (int i = 0; i < N; ++i)
  {
    long long a;
    cin >> a;
    counts[a]++;
  }

  // 集計結果を扱いやすいvectorに変換
  // P[i] = {位置, その位置にいる人数}
  vector<pair<long long, long long>> P;
  P.reserve(counts.size() * 2);
  for (auto const &[pos, count] : counts)
  {
    P.push_back({pos, count});
  }

  int K = P.size();

  // N >= 1, M >= 1 なので通常ここには来ませんが、念のための安全策
  if (K == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  // 円環を扱うため、配列を2倍に拡張する
  // 2周目の位置は 元の位置 + M とする
  for (int i = 0; i < K; ++i)
  {
    P.push_back({P[i].first + M, P[i].second});
  }

  long long total_ans = 0;
  long long current_people_sum = 0; // 現在のウィンドウ内の合計人数
  int right = 0;                    // 尺取り法の右端

  // left: 高橋君が「最初に出会う」人のグループのインデックス
  for (int left = 0; left < K; ++left)
  {

    // 条件 (合計人数 >= C) を満たすまで右端を進める
    while (right < 2 * K && current_people_sum < C)
    {
      current_people_sum += P[right].second;
      right++;
    }

    // 現在のグループ P[left] を「最初に出会う」ことになるスタート地点の数を計算
    // これは「一つ前のグループの位置」から「現在のグループの位置」までの距離に等しい
    long long gap;
    if (left == 0)
    {
      // 先頭の場合は、最後尾(周回前)からの距離
      // (例: M=10, 最後の人が8, 最初の人が1なら、距離は (1+10) - 8 = 3)
      gap = P[0].first + M - P[K - 1].first;
    }
    else
    {
      gap = P[left].first - P[left - 1].first;
    }

    // 答えに加算: (このパターンでの出会う人数) × (該当するスタート地点の数)
    // current_people_sum は、P[left]からP[right-1]までの人数の合計
    total_ans += current_people_sum * gap;

    // 次のループのために、左端の人数を合計から引く
    current_people_sum -= P[left].second;
  }

  cout << total_ans << endl;

  return 0;
}