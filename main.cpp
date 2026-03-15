#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll L, R, D, U;
    cin >> L >> R >> D >> U;

    ll ans = 0;
    for (ll i = D; i <= U; i++)
    {
        // even
        if (i % 2 == 0)
        {
            ans += max(min(abs(i), R), (ll)0);
            // cout << ans << endl;

            ans -= max(min(abs(i), (L - 1)), (ll)0);
            // cout << ans << endl;

            ans += max(R - abs(i), (ll)0) / 2;
            // cout << ans << endl;

            ans -= max((L - 1) - abs(i), (ll)0) / 2;
            // cout << ans << endl;

            ans += max(min(abs(i), -L), (ll)0);
            // cout << ans << endl;

            ans += max(min((ll)0, (R + 1)), -abs(i));
            // cout << ans << endl;

            ans += max(-abs(i) - L, (ll)0) / 2;
            // cout << ans << endl;

            ans -= max(-abs(i) - (R + 1), (ll)0) / 2;
            // cout << ans << endl;

            if ((L <= 0) && (0 <= R))
                ans++;
            // cout << ans << endl;
        }

        // odd
        else
        {
            ans += max(R - abs(i), (ll)0) / 2 + max(R - abs(i), (ll)0) % 2;
            // cout << ans << endl;

            ans -= max((L - 1) - abs(i), (ll)0) / 2 + max((L - 1) - abs(i), (ll)0) % 2;
            // cout << ans << endl;

            ans += max(-abs(i) - L, (ll)0) / 2 + max(-abs(i) - L, (ll)0) % 2;
            // cout << ans << endl;

            ans -= max(-abs(i) - (R + 1), (ll)0) / 2 + max(-abs(i) - (R + 1), (ll)0) % 2;
            // cout << ans << endl;w
        }

        // cout << i << " : " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}