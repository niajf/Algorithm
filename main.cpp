#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  // 0 -> 入力通り、　1 -> 入力反転
  vector<vector<vector<char>>> table(H, vector<vector<char>>(W, vector<char>(2)));

  // 縦、横、深さ(0, 1), 経路
  queue<vector<int>> que;

  // 到達チェック用
  vector<vector<vector<bool>>> ok(H, vector<vector<bool>>(W, vector<bool>(2, false)));

  vector<int> di = {-1, 0, 1, 0};
  vector<int> dj = {0, 1, 0, -1};

  // テーブルの入力受付
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      char c;
      cin >> c;
      table[i][j][0] = c;

      if ((c == '.') || (c == '#') || (c == 'G') || (c == '?'))
        table[i][j][1] = c;

      else if (c == 'S')
      {
        table[i][j][1] = c;
        que.push({i, j, 0, 0});
      }

      else if (c == 'o')
        table[i][j][1] = 'x';

      else if (c == 'x')
        table[i][j][1] = 'o';
    }
  }

  // for (int i = 0; i < H; i++)
  // {
  //   for (int j = 0; j < W; j++)
  //   {
  //     cout << table[i][j][0] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 0; i < H; i++)
  // {
  //   for (int j = 0; j < W; j++)
  //   {
  //     cout << table[i][j][1] << " ";
  //   }
  //   cout << endl;
  // }

  while (!que.empty())
  {
    vector<int> pos = que.front();
    que.pop();

    if (ok[pos[0]][pos[1]][pos[2]])
      continue;

    else
    {
      // ゴール以外の場合は現在の階層のみ探索済みにする
      if (table[pos[0]][pos[1]][pos[2]] != 'G')
        ok[pos[0]][pos[1]][pos[2]] = true;

      // ゴールの場合は探索を終了
      else
      {
        cout << pos[3] << endl;
        return 0;
      }
    }

    // cout << pos[0] << ", " << pos[1] << ", " << pos[2] << ", " << pos[3] << ", " << table[pos[0]][pos[1]][pos[2]] << endl;

    // ?マスの場合は、階層を反転
    int z = pos[2];
    if (table[pos[0]][pos[1]][pos[2]] == '?')
      z = abs(1 - z);

    for (int k = 0; k < 4; k++)
    {
      // 遷移先がテーブルの範囲内か確認
      if ((0 <= pos[0] + di[k]) && (pos[0] + di[k] < H) && (0 <= pos[1] + dj[k]) && (pos[1] + dj[k] < W))
      {
        // 到達できないマスには遷移しない
        if ((table[pos[0] + di[k]][pos[1] + dj[k]][z] == '#') || (table[pos[0] + di[k]][pos[1] + dj[k]][z] == 'x'))
          ;

        // 到達可能なマスには、経路を+1して遷移する
        else
          que.push({pos[0] + di[k], pos[1] + dj[k], z, pos[3] + 1});
      }
    }
  }

  cout << -1 << endl;
  return 0;
}