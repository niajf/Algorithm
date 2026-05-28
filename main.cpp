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
#define rep(i, n) for (int i = 0; i < N; i++)

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<vector<vector<int>>> A(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                cin >> A[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> sum(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                sum[i][j][k] = A[i][j][k] + sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i - 1][j - 1][k] - sum[i][j - 1][k - 1] - sum[i - 1][j][k - 1] + sum[i - 1][j - 1][k - 1];
            }
        }
    }

    // for (auto mat : A)
    // {
    //     for (auto vec : mat)
    //     {
    //         for (auto s : vec)
    //         {
    //             cout << s << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    // for (auto mat : sum)
    // {
    //     for (auto vec : mat)
    //     {
    //         for (auto s : vec)
    //         {
    //             cout << s << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int Q;
    cin >> Q;

    while (Q--)
    {
        vector<int> L(3), R(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> L[i] >> R[i];
        }

        int ans = sum[R[0]][R[1]][R[2]] - sum[L[0] - 1][R[1]][R[2]] - sum[R[0]][R[1]][L[2] - 1] - sum[R[0]][L[1] - 1][R[2]] + sum[R[0]][L[1] - 1][L[2] - 1] + sum[L[0] - 1][R[1]][L[2] - 1] + sum[L[0] - 1][L[1] - 1][R[2]] - sum[L[0] - 1][L[1] - 1][L[2] - 1];

        cout << ans << endl;
    }
    return 0;
}