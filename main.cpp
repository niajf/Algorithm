#include <iostream>
#include <vector>
#include <queue> // std::priority_queueのために必要

#define INF 1e18

// pairの型定義を短くするためのエイリアス（任意）
using P = std::pair<long long, int>;

std::vector<long long> dijkstra(const std::vector<std::vector<std::pair<int, long long>>> &G, int s)
{
  std::vector<long long> dist(G.size(), INF);
  dist[s] = 0;

  // 【改善点1】std::vectorではなく、std::priority_queueを使用する
  // 昇順（小さい順）に取り出すために greater を指定
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.push({0, s});

  while (!pq.empty())
  {
    long long d = pq.top().first;
    int v = pq.top().second;
    pq.pop(); // 【改善点2】popは O(log N) で完了する

    // 既により短い経路が見つかっている場合はスキップ
    if (d > dist[v])
      continue;

    // 範囲ベースforループで記述（わずかに可読性と速度向上）
    for (const auto &edge : G[v])
    {
      int u = edge.first;
      long long weight = edge.second;
      long long nd = d + weight;
      if (dist[u] > nd)
      {
        dist[u] = nd;
        pq.push({nd, u});
      }
    }
  }

  return dist;
}

int main()
{
  // 【改善点3】入出力の高速化
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long N, M;
  std::cin >> N >> M;

  std::vector<long long> A(N);
  for (auto &&a : A)
    std::cin >> a;

  // グラフ構築: 接続先(int)と重み(long long)を保持
  std::vector<std::vector<std::pair<int, long long>>> G(N);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    long long b;
    std::cin >> u >> v >> b;
    u--;
    v--;
    // 重みの計算はここで行う
    G[u].push_back({v, b + A[v]});
    G[v].push_back({u, b + A[u]});
  }

  std::vector<long long> dist = dijkstra(G, 0);

  for (int i = 1; i < N; i++)
    // 【改善点4】std::endl ではなく "\n" または " " を使用
    std::cout << dist[i] + A[0] << (i == N - 1 ? "\n" : " ");

  return 0;
}