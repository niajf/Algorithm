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
int N, M;
vector<vector<int>> arr;

void solve(int start, int depth)
{
    // if (depth == N)
    // {
    //     arr.back().push_back(start);
    //     vector<int> copy = arr.back();
    //     start++;
    //     while (start <= M)
    //     {
    //         arr.push_back(copy);
    //         arr.back().back() = start;
    //         start++;
    //     }

    //     return;
    // }

    vector<int> copy = arr.back();
    for (int i = start; i <= M - (N - depth) * 10; i++)
    {
        if (arr.back().size() >= N)
            arr.push_back(copy);
        arr.back().push_back(i);
        // vector<int> copy = arr.back();

        if (depth < N)
            solve(i + 10, depth + 1);
        // arr.push_back(copy);
    }
}

int main()
{
    cin >> N >> M;
    arr.push_back({});

    int start = 1;
    solve(start, 1);

    cout << arr.size() << endl;
    for (auto vec : arr)
    {
        for (auto n : vec)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}