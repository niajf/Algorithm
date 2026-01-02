#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
  int H, W, D;
  cin >> H >> W >> D;

  vector<string> S(H);
  // 距離を管理する配列。初期値は-1（未訪問）
  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int, int>> q;

  // グリッドの読み込みと加湿器('H')の初期化
  for (int i = 0; i < H; ++i)
  {
    cin >> S[i];
    for (int j = 0; j < W; ++j)
    {
      if (S[i][j] == 'H')
      {
        dist[i][j] = 0; // 加湿器の場所は距離0
        q.push({i, j}); // キューに追加
      }
    }
  }

  // 移動方向（上下左右）
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  // 多始点BFSの実行
  while (!q.empty())
  {
    auto [r, c] = q.front();
    q.pop();

    // 現在の距離がDに達しているなら、これ以上拡散しない
    if (dist[r][c] == D)
      continue;

    for (int i = 0; i < 4; ++i)
    {
      int nr = r + dx[i];
      int nc = c + dy[i];

      // グリッドの範囲内かチェック
      if (nr >= 0 && nr < H && nc >= 0 && nc < W)
      {
        // 壁ではなく、かつ未訪問（最短距離が更新できる）場合
        if (S[nr][nc] != '#' && dist[nr][nc] == -1)
        {
          dist[nr][nc] = dist[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
  }

  // 加湿されたマスの数をカウント
  int ans = 0;
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      // distが-1以外なら到達可能（加湿されている）
      if (dist[i][j] != -1)
      {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}