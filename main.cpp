#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iterator>
#include <iomanip>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, -w});
    }

    vector<ll> ans(N, 0);
    vector<bool> visited(N, false);
    queue<pair<int, pair<int, int>>> que;

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        ans[i] = 0;
        for (auto v : edges[i])
        {
            que.push({i, v});
            ans[v.first] = ans[i] + (ll)v.second;
        }
        while (!que.empty())
        {
            auto [u, v] = que.front();
            que.pop();

            if (visited[v.first])
                continue;

            visited[v.first] = true;
            ans[v.first] = ans[u] + (ll)v.second;
            for (auto p : edges[v.first])
            {
                que.push({v.first, p});
            }
        }

        // for (auto n : ans)
        // {
        //     cout << n << " ";
        // }
        // cout << endl;
    }

    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
}