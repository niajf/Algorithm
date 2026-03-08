#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> A[i];

  vector<vector<int>> adj(N + 1, vector<int>());
  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> ans(N + 1, false);
  unordered_map<int, int> unmap;
  stack<tuple<int, int, bool>> stk;
  int dup = 0;

  stk.push({1, -1, true});

  while (!stk.empty())
  {
    auto [n, p, flag] = stk.top();
    stk.pop();

    // cout << n << " " << p << " " << flag << " " << endl;

    if (flag)
    {
      unmap[A[n]]++;
      if (unmap[A[n]] == 2)
        dup++;

      if (dup > 0)
        ans[n] = true;

      // cout << unmap[A[n]] << endl;
      // cout << dup << endl;

      stk.push({n, p, false});

      for (int node : adj[n])
      {
        if (node != p)
          stk.push({node, n, true});
      }
    }
    else
    {
      if (unmap[A[n]] == 2)
        dup--;
      unmap[A[n]]--;
    }
  }

  for (int i = 1; i <= N; i++)
  {
    cout << (ans[i] ? "Yes" : "No") << endl;
  }

  return 0;
}