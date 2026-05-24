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

int main()
{
    int N;
    double S, T;
    cin >> N >> S >> T;

    double ans = (double)1e308;

    vector<vector<pair<int, int>>> pos(N);

    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        pos[i].push_back({a, b});
        pos[i].push_back({c, d});
    }

    vector<int> perm(N);
    for (int i = 0; i < N; i++)
    {
        perm[i] = i;
    }

    do
    {
        for (int bit = 0; bit < (1 << N); bit++)
        {
            double x = 0.0;
            double y = 0.0;
            double time = 0.0;
            vector<int> B;
            for (int i = 0; i < N; i++)
            {
                if (bit & (1 << i))
                {
                    B.push_back(1);
                    time += sqrt((pos[perm[i]][1].first - x) * (pos[perm[i]][1].first - x) + (pos[perm[i]][1].second - y) * (pos[perm[i]][1].second - y)) / S;
                    x = pos[perm[i]][1].first;
                    y = pos[perm[i]][1].second;
                    // cout << time << " ";
                    time += sqrt((pos[perm[i]][0].first - x) * (pos[perm[i]][0].first - x) + (pos[perm[i]][0].second - y) * (pos[perm[i]][0].second - y)) / T;
                    x = pos[perm[i]][0].first;
                    y = pos[perm[i]][0].second;
                    // cout << time << " ";
                }
                else
                {
                    B.push_back(0);
                    time += sqrt((pos[perm[i]][0].first - x) * (pos[perm[i]][0].first - x) + (pos[perm[i]][0].second - y) * (pos[perm[i]][0].second - y)) / S;
                    x = pos[perm[i]][0].first;
                    y = pos[perm[i]][0].second;
                    // cout << time << " ";
                    time += sqrt((pos[perm[i]][1].first - x) * (pos[perm[i]][1].first - x) + (pos[perm[i]][1].second - y) * (pos[perm[i]][1].second - y)) / T;
                    x = pos[perm[i]][1].first;
                    y = pos[perm[i]][1].second;
                    // cout << time << " ";
                }
            }
            ans = min(ans, time);
            // cout << ans << endl;
            // for (auto n : perm)
            // {
            //     cout << n << " ";
            // }
            // cout << endl;
            // for (auto n : B)
            // {
            //     cout << n << " ";
            // }
            // cout << endl;
        }
    } while (next_permutation(all(perm)));

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}