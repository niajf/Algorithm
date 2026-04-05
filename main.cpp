#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int sizeS = S.size();
    int sizeT = T.size();

    vector<vector<int>> pos(26, vector<int>(sizeS, -1));
    for (int i = 0; i < sizeS; i++)
    {
        pos[S[i] - 'a'][i] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = sizeS - 2; j >= 0; j--)
        {
            if (pos[i][j] == -1)
                pos[i][j] = pos[i][j + 1];
        }
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < sizeS; j++)
    //     {
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    long long ans = 0;
    for (int l = 0; l < sizeS; l++)
    {
        int r = l;
        for (auto c : T)
        {
            if (r >= sizeS)
            {
                r = sizeS + 1;
                break;
            }
            r = pos[c - 'a'][r];
            if (r == -1)
            {
                r = sizeS + 1;
                break;
            }
            r++;
        }

        // cout << l << " " << r << " " << r - l - 1 << endl;

        ans += r - l - 1;
    }

    cout << ans << endl;

    return 0;
}
