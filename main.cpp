#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void serch(std::vector<std::set<int>> const &nodes, std::vector<int> &visited, int node)
{
  for (const auto &s : nodes[node])
  {
    if (visited[s] == 0)
    {
      visited[s] = 1;
      serch(nodes, visited, s);
    }
  }
}

int main()
{
  int N, M;
  std::cin >> N >> M;

  std::vector<std::set<int>> nodes(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    std::cin >> a >> b;

    nodes[a - 1].insert(b - 1);
    nodes[b - 1].insert(a - 1);
  }

  std::vector<int> visited(N, 0);
  int k = 0;
  for (int i = 0; i < N; i++)
  {
    if (visited[i] == 0)
    {
      visited[i] = 1;
      k++;
      serch(nodes, visited, i);
    }
  }

  std::cout << M - (N - k) << std::endl;
}