#include <iostream>
#include <vector>

const int MAX = 2000;

using namespace std;
int main()
{
  int N;
  cin >> N;

  vector<vector<int>> clouds(N, vector<int>(4, 0));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < 4; ++j)
      cin >> clouds[i][j];
  }

  vector<vector<int>> table(MAX + 1, vector<int>(MAX + 1, 0));
  vector<vector<int>> count(MAX + 1, vector<int>(MAX + 1, 0));

  for (int i = 0; i < N; ++i)
  {
    ++table[clouds[i][0] - 1][clouds[i][2] - 1];
    --table[clouds[i][0] - 1][clouds[i][3]];
    --table[clouds[i][1]][clouds[i][2] - 1];
    ++table[clouds[i][1]][clouds[i][3]];
  }

  for (int c = 0; c < MAX; ++c)
  {
    for (int r = 1; r < MAX; ++r)
    {
      table[c][r] += table[c][r - 1];
    }
  }

  int sum = 0;
  for (int r = 0; r < MAX; ++r)
  {
    if (table[0][r] > 0)
      ++sum;
  }

  for (int c = 1; c < MAX; ++c)
  {
    for (int r = 0; r < MAX; ++r)
    {
      table[c][r] += table[c - 1][r];
      if (table[c][r] > 0)
        ++sum;
    }
  }

  for (int c = 0; c < MAX; ++c)
  {
    for (int r = 0; r < MAX; ++r)
    {
      if (table[c][r] == 1)
        count[c + 1][r + 1] = 1;
      else
        count[c + 1][r + 1] = 0;
    }
  }

  for (int c = 0; c <= MAX; ++c)
  {
    for (int r = 1; r <= MAX; ++r)
    {
      count[c][r] += count[c][r - 1];
    }
  }

  for (int c = 1; c <= MAX; ++c)
  {
    for (int r = 0; r <= MAX; ++r)
    {
      count[c][r] += count[c - 1][r];
    }
  }

  // for (int c = 0; c < 10; ++c)
  // {
  //   for (int r = 0; r < 10; ++r)
  //   {
  //     cout << count[c][r] << " ";
  //   }
  //   cout << endl;
  // }

  // cout << sum << endl;

  for (int i = 0; i < N; ++i)
  {
    int c1, c2, r1, r2;
    c1 = clouds[i][0];
    c2 = clouds[i][1];
    r1 = clouds[i][2];
    r2 = clouds[i][3];

    int can_remove = count[c2][r2] - count[c2][r1 - 1] - count[c1 - 1][r2] + count[c1 - 1][r1 - 1];
    // cout << count[c2][r1] << " " << count[c2][r1 - 1] << " " << count[c1 - 1][r2] << " " << count[c1 - 1][r1 - 1] << endl;
    cout << MAX * MAX - (sum - can_remove) << endl;
  }

  return 0;
}