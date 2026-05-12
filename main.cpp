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

using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<set<int>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    set<int> V;
    for (int i = 0; i < K; i++)
    {
        int v;
        cin >> v;
        v--;
        V.insert(v);
    }

    queue<int> deg;
    for (int i = 0; i < N; i++)
    {
        if (edges[i].size() == 1)
            deg.push(i);
    }

    int ans = N;
    while (!deg.empty())
    {
        int node = deg.front();
        deg.pop();

        if (V.count(node))
            continue;

        int target = *edges[node].begin();
        edges[target].erase(node);
        edges[node].erase(target);
        ans--;

        if (edges[target].size() == 1)
            deg.push(target);
    }

    cout << ans << endl;

    return 0;
}