#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int N, L, R;
    cin >> N >> L >> R;

    map<char, vector<int>> mp;
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        mp[c].push_back(i);
    }

    ll ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        auto v = itr->second;
        // cout << endl;

        {
            int l = 0, r = 1;
            ll cnt = 1;
            while ((r < v.size()) && (l != r))
            {
                // cout << v[l] << " " << v[r] << " " << cnt << " ";

                if (v[r] - v[l] <= R)
                {
                    r++;
                    ans += cnt;
                    cnt++;
                }
                else
                {
                    l++;

                    if (l == r)
                        r++;
                    else
                        cnt--;
                }

                // cout << ans << endl;
            }
            // ans += cnt;
        }
        // cout << ans << endl;

        {
            int l = 0, r = 1;
            ll cnt = 1;
            while ((r < v.size()) && (l != r))
            {
                // cout << v[l] << " " << v[r] << " " << cnt << " ";
                if (v[r] - v[l] < L)
                {
                    r++;
                    ans -= cnt;
                    cnt++;
                }
                else
                {
                    l++;

                    if (l == r)
                        r++;
                    else
                        cnt--;
                }
                // cout << ans << endl;
            }
            // ans -= cnt;
        }
        // cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}