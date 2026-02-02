#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N), S(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    S[i] = (i > 0) ? (S[i - 1] + A[i]) : A[i];
  }

  for (int q = 0; q < Q; q++)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int pos;
      cin >> pos;
      S[pos - 1] = S[pos - 1] - (A[pos - 1] - A[pos]);
      swap(A[pos - 1], A[pos]);
    }

    else if (type == 2)
    {
      int s, e;
      cin >> s >> e;

      cout << ((s > 1) ? (S[e - 1] - S[s - 2]) : (S[e - 1])) << endl;
    }

    // for (auto elem : S)
    //   cout << elem << " ";
    // cout << endl;
  }

  return 0;
}