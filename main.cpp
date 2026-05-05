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

using namespace std;
using ll = long long;

const int INF = (int)1e9;

int main()
{
    int N, W;
    cin >> N >> W;

    const int INF = 2e9;

    vector<vector<pair<int, int>>> blocks(W);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        blocks[x].push_back({y, i});
    }

    vector<int> cnt(N, 0);
    vector<int> D(N + 2, 0);

    for (int i = 0; i < W; i++)
    {
        sort(blocks[i].begin(), blocks[i].end());
        for (int j = 0; j < (int)blocks[i].size(); j++)
        {
            cnt[blocks[i][j].second] = j;
            D[j] = max(D[j], blocks[i][j].first);
        }
        D[blocks[i].size()] = INF;
    }

    for (auto d : D)
        cout << d << " ";
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        D[i + 1] = max(D[i + 1], D[i] + 1);
    }

    for (auto d : D)
        cout << d << " ";
    cout << endl;

    int Q;
    cin >> Q;
    while (Q--)
    {
        int T, A;
        cin >> T >> A;
        A--;
        cout << (T < D[cnt[A]] ? "Yes" : "No") << "\n";
    }
    return 0;
}