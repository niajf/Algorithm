#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
  int N, Q;
  std::cin >> N >> Q;

  std::string S;
  std::cin >> S;

  int ans = 0;

  for (int i = 0; i < N - 2; i++)
  {
    if ((S[i] == 'A') && (S[i + 1] == 'B') && (S[i + 2] == 'C'))
      ans++;
  }

  for (int q = 0; q < Q; q++)
  {
    int p;
    char c;
    std::cin >> p >> c;
    p--;

    int pr = 0, ne = 0;

    for (int i = p - 2; i < p + 3; i++)
    {
      if ((S[i] == 'A') && (S[i + 1] == 'B') && (S[i + 2] == 'C'))
        pr++;
    }

    S[p] = c;

    for (int i = p - 2; i < p + 3; i++)
    {
      if ((S[i] == 'A') && (S[i + 1] == 'B') && (S[i + 2] == 'C'))
        ne++;
    }

    ans = ans + (ne - pr);
    std::cout << ans << std::endl;
  }

  return 0;
}