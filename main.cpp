#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; t++)
  {
    int N;
    cin >> N;

    vector<int> R(N), S(N);
    for (auto &&r : R)
      cin >> r;
    copy(R.begin(), R.end(), S.begin());

    for (int i = 1; i < N; i++)
      R[i] = min(R[i], R[i - 1] + 1);

    for (int i = N - 2; i >= 0; i--)
      R[i] = min(R[i], R[i + 1] + 1);

    long long ans = 0;
    for (int i = 0; i < N; i++)
      ans += S[i] - R[i];

    cout << ans << endl;
  }

  return 0;
}