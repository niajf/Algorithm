#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 100000000;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<char>> table(H, vector<char>(W));
  map<char, vector<pair<int, int>>> m;

  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      cin >> table[h][w];
      if (m.count(table[h][w]))
        m[table[h][w]].push_back({h, w});
      else
        m[table[h][w]] = {{h, w}};
    }
  }

  vector<int> mv = {-1, 0, 1, 0};
  vector<int> mh = {0, 1, 0, -1};

  using pp = pair<int, int>;
  using pcp = pair<int, pp>;
  priority_queue<pcp, vector<pcp>, greater<pcp>> que;
  que.push({0, {0, 0}});

  vector<vector<int>> minimum(H, vector<int>(W, INF));
  // minimum[0][0] = 0;

  while (!que.empty())
  {
    pcp s = que.top();
    que.pop();

    // if (s.first > minimum[s.second.first][s.second.second])
    //   continue;

    if (table[s.second.first][s.second.second] != '.')
    {
      for (auto p : m[table[s.second.first][s.second.second]])
      {
        if (((p.first != s.second.first) || (p.second != s.second.second)) && (minimum[p.first][p.second] > s.first + 1))
        {
          que.push({s.first + 1, {p.first, p.second}});
          minimum[p.first][p.second] = s.first + 1;
        }
      }
    }
    m.erase(table[s.second.first][s.second.second]);

    if (s.first < minimum[s.second.first][s.second.second])
      minimum[s.second.first][s.second.second] = s.first;

    // cout << s.first << " : " << s.second.first << ", " << s.second.second << endl;

    for (int i = 0; i < 4; i++)
    {
      if ((0 > s.second.first + mv[i]) || (s.second.first + mv[i] >= H) || (0 > s.second.second + mh[i]) || (s.second.second + mh[i] >= W))
        continue;

      else if (table[s.second.first + mv[i]][s.second.second + mh[i]] == '#')
        continue;

      else if (table[s.second.first + mv[i]][s.second.second + mh[i]] == '.')
      {
        if (minimum[s.second.first + mv[i]][s.second.second + mh[i]] > s.first + 1)
        {
          que.push({s.first + 1, {s.second.first + mv[i], s.second.second + mh[i]}});
          minimum[s.second.first + mv[i]][s.second.second + mh[i]] = s.first + 1;
        }
      }

      else
      {
        if (minimum[s.second.first + mv[i]][s.second.second + mh[i]] > s.first + 1)
        {
          que.push({s.first + 1, {s.second.first + mv[i], s.second.second + mh[i]}});
          minimum[s.second.first + mv[i]][s.second.second + mh[i]] = s.first + 1;
        }
      }
    }
  }

  cout << ((minimum[H - 1][W - 1] == INF) ? (-1) : (minimum[H - 1][W - 1])) << endl;
  return 0;
}
