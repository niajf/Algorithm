#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N;
    string S;
    cin >> N >> S;

    int max0 = 0;
    int max1 = 0;
    int cont0 = 0;
    int cont1 = 0;
    int r0 = 0, r1 = 0;

    for (int i = 0; i < N; i++)
    {
      if (S[i] == '0')
      {
        if (max1 < cont1)
        {
          r1 = i;
          max1 = cont1;
        }
        cont1 = 0;
        cont0++;
      }
      else if (S[i] == '1')
      {
        if (max0 < cont0)
        {
          r0 = i;
          max0 = cont0;
        }
        cont0 = 0;
        cont1++;
      }
    }

    if (max0 < cont0)
    {
      max0 = cont0;
      r0 = N;
    }
    if (max1 < cont1)
    {
      max1 = cont1;
      r1 = N;
    }

    int ans0 = 0;
    int ans1 = 0;
    for (int i = 0; i < N; i++)
    {
      if (((r0 - max0 > i) || (i >= r0)))
      {
        if (S[i] == '0')
          ans0 += 2;
        else
          ans0 += 1;
      }

      if (((r1 - max1 > i) || (i >= r1)))
      {
        if (S[i] == '1')
          ans1 += 2;
        else
          ans1 += 1;
      }
    }

    cout << min(ans0, ans1) << "\n";
  }
}