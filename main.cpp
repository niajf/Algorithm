
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 3e5

int main()
{
  int N, M;
  std::cin >> N >> M;

  std::vector<int> A(N);
  int max = -1;
  for (int n = 0; n < N; n++)
  {
    std::cin >> A[n];
    max = std::max(A[n], max);
  }

  std::vector<int> C(2e5, MAX);
  for (int n = 0; n < N; n++)
  {
    if (C[A[n] - 1] == MAX)
      C[A[n] - 1] = n + 1;
  }

  int min = C[0];
  for (int i = 0; i < C.size(); i++)
  {
    C[i] = std::min(min, C[i]);
    min = C[i];
  }

  // for (auto const elem : C)
  //   std::cout << elem << " ";
  // std::cout << std::endl;

  for (int m = 0; m < M; m++)
  {
    int b;
    std::cin >> b;
    int v = (C[b - 1] == MAX) ? -1 : C[b - 1];
    std::cout << v << std::endl;
  }

  return 0;
}