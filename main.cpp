#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main()
{
  int N, M, S, T, L;
  cin >> N >> M >> L >> S >> T;

  // in out cost
  vector<vector<pair<int, int>>> edges(N);
  for (int i = 0; i < M; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    edges[u - 1].push_back({v - 1, c});
  }

  // node remain_count total_cost
  queue<vector<long long>> que;
  que.push({0, L, 0});

  set<int> ok;

  while (!que.empty())
  {
    auto node = que.front();
    que.pop();

    if (node[1] == 0)
    {
      if ((S <= node[2]) && (node[2] <= T))
        ok.insert(node[0]);

      continue;
    }

    for (auto const p : edges[node[0]])
      que.push({p.first, node[1] - 1, node[2] + p.second});
  }

  for (auto node : ok)
    cout << node + 1 << " ";
  cout << endl;

  return 0;
}