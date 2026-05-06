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

// Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector<bool> isprime;
// 返り値は素数のリスト。
vector<ll> Era(int n)
{
    isprime.resize(n, true);
    vector<ll> res;
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i < n; ++i)
        isprime[i] = true;
    for (ll i = 2; i < n; ++i)
    {
        if (isprime[i])
        {
            res.push_back(i);
            for (ll j = i * 2; j < n; j += i)
                isprime[j] = false;
        }
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;
    vector<ll> v = Era(1000005);
    for (ll p : v)
    {
        if (p * p * p * p * p * p * p * p <= N)
            ans++;
        else
            break;
    }

    for (ll p : v)
    {
        if (p * p * p * p > N)
            break;

        for (ll q : v)
        {
            if (q <= p)
                continue;

            if (p * p * q * q <= N)
                ans++;
            else
                break;
        }
    }

    cout << ans << endl;

    return 0;
}