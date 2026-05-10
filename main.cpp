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
const int INF = (int)1e9;

int main()
{
    ll N, K;
    cin >> N >> K;

    ll l = 1e18;
    ll r = 9e18;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        l = min(l, A[i]);
    }

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        bool ok = true;
        for (int i = 0; i < N; i++)
        {
            if (A[i] >= mid)
                continue;

            ll add = (mid - A[i] + i) / (i + 1);

            if (cnt > K - add)
            {
                ok = false;
                break;
            }

            cnt += add;
        }

        if (ok)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r << endl;

    return 0;
}