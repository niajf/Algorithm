#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// 矩形を表す構造体（閉区間 [xl, xr] x [yl, yr]）
struct Rect
{
  long long xl, xr; // 行 (Row) 範囲
  long long yl, yr; // 列 (Column) 範囲

  long long area() const
  {
    return (xr - xl + 1) * (yr - yl + 1);
  }
};

// Union-Find (DSU) の簡易実装
struct DSU
{
  vector<int> parent;
  DSU(int n) : parent(n)
  {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x)
  {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
      parent[rootX] = rootY;
  }
};

int main()
{
  int N;
  long long H, W;
  if (!(cin >> N >> H >> W))
    return 0;

  vector<string> C(N);
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> C[i] >> A[i] >> B[i];
  }

  // 初期状態は1枚の巨大な矩形
  vector<Rect> rects;
  rects.push_back({0, H - 1, 0, W - 1});

  for (int i = 0; i < N; ++i)
  {
    vector<Rect> next_rects;
    long long split_pos = A[i];
    long long shift = B[i];

    if (C[i] == "X")
    {
      // 行(x)で分割し、列(y)をずらす
      for (const auto &r : rects)
      {
        // 1. 分割線より完全に上 (x < A) -> yを -B ずらす
        if (r.xr < split_pos)
        {
          next_rects.push_back({r.xl, r.xr, r.yl - shift, r.yr - shift});
        }
        // 2. 分割線より完全に下 (x >= A) -> yを +B ずらす
        else if (r.xl >= split_pos)
        {
          next_rects.push_back({r.xl, r.xr, r.yl + shift, r.yr + shift});
        }
        // 3. 分割線をまたぐ -> 上下2つに分割してそれぞれずらす
        else
        {
          // 上側 (x < A)
          next_rects.push_back({r.xl, split_pos - 1, r.yl - shift, r.yr - shift});
          // 下側 (x >= A)
          next_rects.push_back({split_pos, r.xr, r.yl + shift, r.yr + shift});
        }
      }
    }
    else
    { // C[i] == "Y"
      // 列(y)で分割し、行(x)をずらす
      for (const auto &r : rects)
      {
        // 1. 分割線より完全に左 (y < A) -> xを -B ずらす
        if (r.yr < split_pos)
        {
          next_rects.push_back({r.xl - shift, r.xr - shift, r.yl, r.yr});
        }
        // 2. 分割線より完全に右 (y >= A) -> xを +B ずらす
        else if (r.yl >= split_pos)
        {
          next_rects.push_back({r.xl + shift, r.xr + shift, r.yl, r.yr});
        }
        // 3. 分割線をまたぐ -> 左右2つに分割してそれぞれずらす
        else
        {
          // 左側 (y < A)
          next_rects.push_back({r.xl - shift, r.xr - shift, r.yl, split_pos - 1});
          // 右側 (y >= A)
          next_rects.push_back({r.xl + shift, r.xr + shift, split_pos, r.yr});
        }
      }
    }
    rects = next_rects;
  }

  // 連結成分の判定
  int M = rects.size();
  DSU dsu(M);

  for (int i = 0; i < M; ++i)
  {
    for (int j = i + 1; j < M; ++j)
    {
      const Rect &s = rects[i];
      const Rect &t = rects[j];

      // X方向の接触判定 (Gapが0であることの判定)
      // sの右端+1がtの左端、またはtの右端+1がsの左端
      bool x_touch_exact = (s.xr + 1 == t.xl) || (t.xr + 1 == s.xl);
      // 単なる区間の重なり（接触含む）
      bool x_overlap = !(s.xr + 1 <= t.xl) && !(t.xr + 1 <= s.xl);

      // Y方向の接触判定
      bool y_touch_exact = (s.yr + 1 == t.yl) || (t.yr + 1 == s.yl);
      bool y_overlap = !(s.yr + 1 <= t.yl) && !(t.yr + 1 <= s.yl);

      // 連結条件:
      // (行がぴったりくっついていて、列が重なっている) OR (列がぴったりくっついていて、行が重なっている)
      if ((x_touch_exact && y_overlap) || (y_touch_exact && x_overlap))
      {
        dsu.unite(i, j);
      }
    }
  }

  // 連結成分ごとの面積集計
  // グループID -> 面積合計
  // (グループIDは 0~M-1 の範囲になるため vector で管理可能)
  vector<long long> group_sizes(M, 0);
  for (int i = 0; i < M; ++i)
  {
    group_sizes[dsu.find(i)] += rects[i].area();
  }

  // 面積が0より大きいものを抽出してソート
  vector<long long> results;
  for (int i = 0; i < M; ++i)
  {
    // 親(代表元)の場所にだけ合計値が入っている
    if (dsu.parent[i] == i && group_sizes[i] > 0)
    {
      results.push_back(group_sizes[i]);
    }
  }
  sort(results.begin(), results.end());

  // 出力
  cout << results.size() << "\n";
  for (size_t i = 0; i < results.size(); ++i)
  {
    cout << results[i] << (i == results.size() - 1 ? "" : " ");
  }
  cout << "\n";

  return 0;
}