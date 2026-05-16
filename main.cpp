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

    vector<int> A(N);
    vector<int> zero(N, 0);
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            zero[i] += zero[i - 1];

        int n = i + A[i] + i - zero[i];
        if (n < N)
        {
            zero[n + 1]++;
            ans[i] = 0;
        }
        else
            ans[i] = A[i] + i - (N - i - 1) - zero[i];
    }

    // for (auto n : zero)
    //     cout << n << " ";
    // cout << endl;

    for (auto n : ans)
        cout << n << " ";
    cout << endl;

    return 0;
}