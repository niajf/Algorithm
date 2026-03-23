#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        vector<char> S, ans;

        cin >> N;
        S.resize(N);

        for (int i = 0; i < N; i++)
            cin >> S[i];

        int l = 0;
        {
            bool isEnd = true;
            for (int i = 0; i < N - 1; i++)
            {
                if (S[i] > S[i + 1])
                {
                    l = i;
                    isEnd = false;
                    break;
                }

                ans.push_back(S[i]);
            }

            if (isEnd)
            {
                l = N - 1;
            }
        }

        {
            bool isEnd = true;
            for (int i = l + 1; i < N; i++)
            {
                if (isEnd && S[l] < S[i])
                {
                    ans.push_back(S[l]);
                    isEnd = false;
                }
                ans.push_back(S[i]);
            }

            if (isEnd)
                ans.push_back(S[l]);
        }

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << "\n";
    }

    return 0;
}
