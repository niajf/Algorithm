#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int H, W;

int count(pair<int, int> pos, set<pair<int, int>> &aleady)
{
  vector<int> colMat = {-1, 0, 1, 0};
  vector<int> rowMat = {0, 1, 0, -1};

  int cnt = 0;
  for (int i = 0; i < 4; i++)
  {
    if ((0 <= pos.first + colMat[i]) && (pos.first + colMat[i] < H) && (0 <= pos.second + rowMat[i]) && (pos.second + rowMat[i] < W))
    {
      if (aleady.count({pos.first + colMat[i], pos.second + rowMat[i]}))
        cnt++;
    }
  }

  return cnt;
}

int main()
{
  cin >> H >> W;

  vector<pair<int, int>> initialPos;
  set<pair<int, int>> aleadyPos;

  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> table[i][j];
      if (table[i][j] == '#')
      {
        initialPos.push_back({i, j});
      }
    }
  }

  vector<int> colMat = {-1, 0, 1, 0};
  vector<int> rowMat = {0, 1, 0, -1};

  ll prevSize = 0;
  while (true)
  {
    map<pair<int, int>, ll> M;
    for (int i = prevSize; i < initialPos.size(); i++)
    {
      auto pos = initialPos[i];
      if (aleadyPos.count(pos) > 0)
        continue;
      else
        aleadyPos.insert(pos);

      for (int i = 0; i < 4; i++)
      {
        if ((0 <= pos.first + colMat[i]) && (pos.first + colMat[i] < H) && (0 <= pos.second + rowMat[i]) && (pos.second + rowMat[i] < W))
          M[{pos.first + colMat[i], pos.second + rowMat[i]}]++;
      }
    }

    prevSize = initialPos.size();
    for (auto iter = M.begin(); iter != M.end(); ++iter)
    {
      if ((iter->second == 1) && (!aleadyPos.count(iter->first)) && (count(iter->first, aleadyPos) == 1))
        initialPos.push_back(iter->first);
    }

    // cout << prevSize << " " << initialPos.size() << "\n";
    if (initialPos.size() == prevSize)
      break;
  }

  // for (int i = 0; i < initialPos.size(); i++)
  //   cout << initialPos[i].first << ", " << initialPos[i].second << "\n";

  cout << initialPos.size() << "\n";
}