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

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<double> K(N);
    vector<unordered_map<int, double>> A(N);
    vector<set<int>> sets(N);
    for (int i = 0; i < N; i++)
    {
        cin >> K[i];
        for (int k = 0; k < K[i]; k++)
        {
            int a;
            cin >> a;
            a--;
            A[i][a]++;
            sets[i].insert(a);
        }
    }

    double ans = 0.f;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            set<int> res;
            set_intersection(all(sets[i]), all(sets[j]), inserter(res, res.end()));
            double prob = 0.f;
            for (const auto key : res)
            {
                prob += (A[i][key] / K[i]) * (A[j][key] / K[j]);
            }
            ans = max(ans, prob);
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}