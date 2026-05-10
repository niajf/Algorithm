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

int main()
{
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    stack<int> stk;
    vector<int> ans = {0};
    for (int i = N - 2; i >= 0; i--)
    {
        if (!stk.empty())
        {
            while (!stk.empty() && stk.top() < H[i + 1])
            {
                stk.pop();
            }
        }

        stk.push(H[i + 1]);
        ans.push_back((int)stk.size());
    }

    reverse(ans.begin(), ans.end());
    for (auto n : ans)
        cout << n << " ";
    cout << endl;

    return 0;
}