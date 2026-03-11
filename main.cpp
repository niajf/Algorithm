#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    ll N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> A[i];
      sumA += A[i];
    }

    for (int i = 0; i < N; i++)
    {
      cin >> B[i];
      sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int s = 0, e = N - 1;
    ll c = 0;
    while ((e >= 0) && (s < N))
    {
      if (A[e] + B[s] >= M)
      {
        c++;
        e--;
        s++;
      }
      else
      {
        s++;
      }
    }

    cout << sumA + sumB - c * M << endl;
  }
  return 0;
}