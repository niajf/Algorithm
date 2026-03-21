#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A[i] = a % K;
    }

    sort(A.begin(), A.end());

    // for (int i = 0; i < N; i++)
    // {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    int opt = A[N - 1] - A[0];
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] + K - A[i + 1] < opt)
            opt = A[i] + K - A[i + 1];
    }

    cout << opt << endl;

    return 0;
}
