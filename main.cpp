#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;

        A--;
        B--;
        adj[A].push_back({B, W});
    }

    vector<vector<bool>> visited(N, vector<bool>((1 << 10), false));
    queue<tuple<int, int, int>> que;
    que.push({0, 0, 0});

    while (!que.empty())
    {
        auto [node, wei, val] = que.front();
        que.pop();

        val = val ^ wei;
        if (visited[node][val])
            continue;
        else
            visited[node][val] = 1;

        for (auto [n, w] : adj[node])
            que.push({n, w, val});
    }

    for (int i = 0; i < (1 << 10); i++)
    {
        if (visited[N - 1][i])
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}
