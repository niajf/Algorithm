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

const ll INF = -(1LL << 60);

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto &a : A)
        cin >> a;

    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));

    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        // 倒さない
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);

        // 倒す
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + A[i]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2 * A[i]);
    }

    // for (auto vec : dp)
    // {
    //     for (auto p : vec)
    //     {
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }

    cout << max(dp[N][0], dp[N][1]) << endl;
}