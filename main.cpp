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

ll solve(ll n, ll k, bool &flip)
{
    if (n < k)
    {
        flip = !flip;
        ll base = n;
        while (base < k)
        {
            base *= 2;
        }
        base /= 2;
        return k - base;
    }

    return k;
}

int main()
{
    string S;
    int Q;
    cin >> S >> Q;

    ll N = S.size();
    vector<ll> K(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> K[i];
    }

    for (int i = 0; i < Q; i++)
    {

        ll base = N;
        ll num = K[i];
        bool flip = false;

        while (true)
        {
            ll rem = solve(base, num, flip);

            if (rem > N)
            {
                num = rem;
                continue;
            }
            else
            {
                num = rem;
                break;
            }
        }

        char c = S[num - 1];
        if (flip)
        {
            if (islower(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
        cout << c << " ";
    }
    cout << endl;

    return 0;
}