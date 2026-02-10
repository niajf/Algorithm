#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
int main()
{
  int N, M;
  cin >> N >> M;

  map<int, vector<int>> edges;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;

    if (edges.count(v))
      edges[v].push_back(u);
    else
      edges[v] = {u};
  }

  int Q;
  cin >> Q;

  vector<int> visited(N + 1, 0);
  for (int i = 0; i < Q; i++)
  {
    int type, node;
    cin >> type >> node;

    if (type == 1)
    {
      if (!visited[node])
      {
        queue<int> que;
        que.push(node);
        visited[node] = 1;

        while (!que.empty())
        {
          int n = que.front();
          que.pop();

          for (auto const e : edges[n])
          {
            if (!visited[e])
            {
              visited[e] = 1;
              que.push(e);
            }
          }
        }
      }
    }

    else if (type == 2)
    {
      if (visited[node])
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}