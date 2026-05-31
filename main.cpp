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
#define rep(i, l, r) for (int i = l; i < r; i++)

using namespace std;
using ll = long long;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<int> C(N);
    rep(i, 0, N)
    {
        cin >> C[i];
    }

    vector<vector<ll>> left(N, vector<ll>(2)), right(N, vector<ll>(2));
    left[0][0] = (S[0] == '0' ? 0 : C[0]);
    left[0][1] = (S[0] == '1' ? 0 : C[0]);
    for (int i = 1; i < N; i++)
    {
        left[i][0] = left[i - 1][1] + (S[i] == '0' ? 0 : C[i]);
        left[i][1] = left[i - 1][0] + (S[i] == '1' ? 0 : C[i]);
    }

    right[N - 1][0] = (S[N - 1] == '0' ? 0 : C[N - 1]);
    right[N - 1][1] = (S[N - 1] == '1' ? 0 : C[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        right[i][0] = right[i + 1][1] + (S[i] == '0' ? 0 : C[i]);
        right[i][1] = right[i + 1][0] + (S[i] == '1' ? 0 : C[i]);
    }

    ll ans = (ll)1e18;
    for (int i = 0; i < N - 1; i++)
    {
        ans = min(ans, min(left[i][0] + right[i + 1][0], left[i][1] + right[i + 1][1]));
    }

    cout << ans << endl;

    // for (auto vec : left)
    // {
    //     for (auto n : vec)
    //         cout << n << " ";
    //     cout << endl;
    // }

    // cout << endl;

    // for (auto vec : right)
    // {
    //     for (auto n : vec)
    //         cout << n << " ";
    //     cout << endl;

    return 0;
}