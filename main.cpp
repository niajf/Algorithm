#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long int ll;

ll int_pow(ll a, ll t)
{
  ll res = 1;
  for (int i = 0; i < t; i++)
    res *= a;
  return res;
}

ll count(ll r)
{

  ll high = r;
  std::vector<int> digits;
  while (high)
  {
    digits.push_back(high % 10);
    high /= 10;
  }

  std::reverse(digits.begin(), digits.end());
  int n = digits.size();

  ll res = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i == n)
    {
      res++;
      break;
    }

    else
      res += int_pow(digits[0], n - 1 - i) * std::min(digits[0], digits[i]);

    if (digits[0] <= digits[i])
      break;
  }

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      for (int j = 1; j < digits[0]; j++)
        res += int_pow(j, n - i - 1);
    }

    else
    {
      for (int j = 1; j <= 9; j++)
        res += int_pow(j, n - i - 1);
    }
  }

  return res;
}

int main()
{
  ll l, r;
  std::cin >> l >> r;

  std::cout << count(r) - count(l - 1) << std::endl;

  return 0;
}