#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<long long> S(N);
        long long l, r;
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
            S[i] *= -1;
        }

        l = S[0];
        r = S[N - 1];

        sort(S.begin(), S.end());

        auto beginIter = lower_bound(S.begin(), S.end(), l);
        auto endIter = lower_bound(S.begin(), S.end(), r);

        // cout << endl;
        // cout << "start : " << *beginIter << endl;
        // cout << "end : " << *endIter << endl;

        if (*beginIter <= *endIter)
        {
            cout << 2 << endl;
            continue;
        }

        int ans = 1;
        bool ok = false;

        while (beginIter != endIter)
        {

            auto iter = lower_bound(endIter, beginIter - 1, 2 * (*beginIter));
            ans++;

            // cout << 2 * (*beginIter) << " : " << *iter << endl;

            if ((2 * (*beginIter) > *iter))
                break;

            else if ((iter == endIter))
            {
                ok = true;
                break;
            }

            beginIter = iter;
        }

        if (ok)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
