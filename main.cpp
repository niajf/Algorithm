#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int N, M;
  string S, T;
  cin >> N >> M >> S >> T;

  vector<int> vec(N + 1, 0);
  for (int i = 0; i < M; i++)
  {
    int L, R;
    cin >> L >> R;
    vec[L - 1]++;
    vec[R]--;
  }

  for (int i = 0; i < N; i++)
  {
    if (i > 0)
      vec[i] = vec[i] + vec[i - 1];

    if (vec[i] % 2)
      cout << T[i];
    else
      cout << S[i];
  }
  cout << endl;

  return 0;
}