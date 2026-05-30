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
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
using ll = long long;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> table(H);
    for (int i = 0; i < H; i++)
        cin >> table[i];

    vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dj = {0, 1, 1, 1, 0, -1, -1, -1};

    auto in = [&](int i, int j)
    { return 0 <= i && i < H && 0 <= j && j < W; };

    // 前処理: 元の # の8近傍の . を # に塗り替える(始点を1マスシフト)
    vector<string> base(H, string(W, '.'));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (table[i][j] == '#')
                for (int k = 0; k < 8; k++)
                {
                    int ni = i + di[k], nj = j + dj[k];
                    if (in(ni, nj) && table[ni][nj] == '.')
                        base[ni][nj] = '#';
                }

    // 塗り替え後の # を距離0の始点として多重始点BFS
    queue<tuple<int, int, int>> que;
    vector<vector<int>> cntMat(H, vector<int>(W, -2));

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (base[i][j] == '#')
                que.push({i, j, 0});

    while (!que.empty())
    {
        auto [i, j, cnt] = que.front();
        que.pop();

        if (cntMat[i][j] != -2)
            continue;
        cntMat[i][j] = cnt;

        for (int k = 0; k < 8; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (!in(ni, nj))
                continue;
            if (cntMat[ni][nj] != -2)
                continue;

            que.push({ni, nj, cnt + 1});
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << (cntMat[i][j] % 2 == 0 ? '.' : '#');
        cout << '\n';
    }

    return 0;
}