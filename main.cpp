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
    int X, Q;
    cin >> X >> Q;

    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    low.push(X);

    for (int i = 1; i <= Q; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int v : {a, b})
        {
            if (v <= low.top())
            {
                low.push(v);
            }
            else
            {
                high.push(v);
            }
        }

        int target_low = i + 1;
        while ((int)low.size() > target_low)
        {
            high.push(low.top());
            low.pop();
        }
        while ((int)low.size() < target_low)
        {
            low.push(high.top());
            high.pop();
        }

        cout << low.top() << "\n";
    }

    return 0;
}