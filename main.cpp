#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recursion(int num, int r)
{
  pair<int, int> p;
  p.first = num / 2;
  p.second = num - p.first;

  if (r > 0)
  {
    recursion(p.first, r - 1);
    recursion(p.second, r - 1);
  }
  else
  {
    cout << p.first << " " << p.second << " ";
  }
}

int main()
{
  int N, K;
  cin >> N >> K;

  int elem = 1;
  for (int i = 0; i < N; i++)
    elem *= 2;

  if ((K / elem) * elem == K)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";

  recursion(K, N - 1);
  cout << "\n";

  return 0;
}