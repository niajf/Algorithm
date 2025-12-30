#include <iostream>
#include <string>

bool insert(std::string const &s, std::string const &t)
{

  int offset = 0;
  int c = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != t[i + offset])
    {
      c++;
      offset++;
      if (c > 1)
        return false;
    }
  }

  return true;
}

bool change(std::string const &s, std::string const &t)
{
  int c = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != t[i])
    {
      c++;
      if (c > 1)
        return false;
    }
  }
  return true;
}

int main()
{
  int k;
  std::cin >> k;

  std::string s, t;
  std::cin >> s >> t;

  bool ok = false;

  if (s == t)
    ok = true;

  // insert
  else if (s.size() + 1 == t.size())
    ok = insert(s, t);

  else if (s.size() - 1 == t.size())
    ok = insert(t, s);

  else if (s.size() == t.size())
    ok = change(s, t);

  if (ok)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}