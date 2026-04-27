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

bool in(ll x, ll y, ll R)
{
    return (2 * x + 1) * (2 * x + 1) + (2 * y + 1) * (2 * y + 1) <= 4 * R * R;
}

int main()
{
    ll R;
    cin >> R;

    ll res = 4 * (R - 1) + 1;
    ll cnt = 0;
    ll up = R - 1;

    for (ll i = 1; i < R; i++)
    {
        while (!in(i, up, R))
            up--;

        cnt += up;
    }

    res += 4 * cnt;
    cout << res << endl;

    return 0;
}