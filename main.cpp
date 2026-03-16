#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num > 0)
            A[i] = {abs(num), 1};
        else
            A[i] = {abs(num), -1};
    }

    bool allSame = true;
    bool absSame = true;
    int neg = 0, pos = 0;

    int a = A[0].first * A[0].second;
    int absa = A[0].first;

    for (int i = 0; i < N; i++)
    {
        if (A[i].first * A[i].second != a)
            allSame = false;

        if (A[i].first != absa)
            absSame = false;

        if (A[i].second > 0)
            pos++;
        else
            neg++;
    }

    if (allSame)
    {
        // cout << 1 << endl;
        return true;
    }

    if ((absSame) && (min(neg, pos) == N / 2))
    {
        // cout << 2 << endl;
        return true;
    }

    sort(A.begin(), A.end());
    for (int i = 1; i < N - 1; i++)
    {
        if ((A[i].first * A[i].second) * (A[i].first * A[i].second) != (A[i - 1].first * A[i - 1].second) * (A[i + 1].first * A[i + 1].second))
        {
            // cout << 3 << endl;
            return false;
        }
    }

    // cout << 4 << endl;
    return true;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}