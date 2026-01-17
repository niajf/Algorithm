#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

int main()
{
  int N;
  std::cin >> N;
  std::set<std::pair<int, int>> G_edges, H_edges;

  int Mg;
  std::cin >> Mg;
  for (int i = 0; i < Mg; i++)
  {
    int u, v;
    std::cin >> u >> v;
    G_edges.insert({u - 1, v - 1});
    G_edges.insert({v - 1, u - 1});
  }

  int Mh;
  std::cin >> Mh;
  for (int i = 0; i < Mh; i++)
  {
    int u, v;
    std::cin >> u >> v;
    H_edges.insert({u - 1, v - 1});
    H_edges.insert({v - 1, u - 1});
  }

  std::vector<std::vector<int>> A(N, std::vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      std::cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }

  std::vector<int> P(N);
  std::iota(P.begin(), P.end(), 0);

  int ans = N * (N - 1) / 2 * 1e6;

  do
  {
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < i; j++)
      {
        sum += A[i][j] * (H_edges.contains({i, j}) != G_edges.contains({P[i], P[j]}));
      }
    }

    ans = std::min(ans, sum);
  } while (std::next_permutation(P.begin(), P.end()));

  std::cout << ans << std::endl;

  return 0;
}