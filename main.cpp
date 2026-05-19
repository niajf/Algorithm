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

using namespace std;
using ll = long long;

int H, W, K;
int ans = 0;
vector<vector<char>> table;
vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

void dfs(int i, int j, int cnt, vector<vector<bool>> &visited)
{
    visited[i][j] = true;

    if (cnt == K)
    {
        ans++;
        visited[i][j] = false;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (!(0 <= ni && ni < H && 0 <= nj && nj < W))
            continue;

        if (table[ni][nj] == '#')
            continue;

        if (!visited[ni][nj])
            dfs(ni, nj, cnt + 1, visited);
    }

    visited[i][j] = false;
}

int main()
{
    // int H, W, K;
    cin >> H >> W >> K;
    table.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (table[i][j] != '.')
                continue;

            vector<vector<bool>> visited(H, vector<bool>(W, false));
            dfs(i, j, 0, visited);
        }
    }

    cout << ans << endl;

    return 0;
}