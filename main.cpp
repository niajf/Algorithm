#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<ll> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i] >> C[i];
  }

  vector<ll> entry(N, -1);

  priority_queue<
      pair<ll, ll>,
      vector<pair<ll, ll>>,
      greater<>>
      heap;

  ll occupancy = 0;
  ll time = 0;

  entry[0] = A[0];
  occupancy = C[0];
  time = A[0];
  heap.push({time + B[0], C[0]});

  for (int i = 1; i < N; i++)
  {
    time = max(A[i], time);

    while (!heap.empty() && heap.top().first < time)
    {
      occupancy -= heap.top().second;
      heap.pop();
    }

    while (occupancy + C[i] > K)
    {
      pair<ll, ll> p = heap.top();
      heap.pop();
      time = p.first;
      occupancy -= p.second;
    }

    occupancy += C[i];
    heap.push({time + B[i], C[i]});
    entry[i] = time;
  }

  for (int i = 0; i < N; i++)
    cout << entry[i] << endl;

  return 0;
}