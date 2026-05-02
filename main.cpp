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

int main()
{
    string S;
    cin >> S;

    ll dp[3] = {0, 0, 0};

    for (char ch : S)
    {
        int c = ch - 'a';
        ll ne = (dp[(c + 1) % 3] + dp[(c + 2) % 3] + 1) % 998244353;
        dp[c] = (dp[c] + ne) % 998244353;
    }

    ll ans = (dp[0] + dp[1] + dp[2]) % 998244353;
    cout << ans << endl;

    return 0;
}