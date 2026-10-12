#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iterator>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cfloat>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, l, r, p) for (int i = l; i < r; i += p)

// const float PI = 3.14159265359;

using namespace std;
using ll = long long;

int main()
{
	int N, Q;
	cin >> N >> Q;

	vector<vector<int>> bestFromNode(N, vector<int>(2, 0));
	vector<ll> L(N, INT_MAX), R(N, INT_MAX);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> L[i + 1];
	}

	for (int i = 0; i < N - 1; i++)
	{
		cin >> R[i];
	}

	{
		ll best = L[N - 1];
		int bestIdx = N - 1;
		bestFromNode[N - 1][1] = -1;
		for (int i = N - 2; i >= 0; i--)
		{
			bestFromNode[i][1] = bestIdx;

			if (best > L[i])
			{
				best = L[i];
				bestIdx = i;
			}
		}
	}

	{
		ll best = R[0];
		int bestIdx = 0;
		bestFromNode[0][0] = -1;
		for (int i = 1; i < N; i++)
		{
			bestFromNode[i][0] = bestIdx;

			if (best > R[i])
			{
				best = R[i];
				bestIdx = i;
			}
		}
	}

	for (auto i : L)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto i : R)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << bestFromNode[i][0] << " " << bestFromNode[i][1] << endl;
	}
	cout << endl;

	while (Q--)
	{
		int s, t;
		cin >> s >> t;

		s--;
		t--;

		if (s == 0)
		{
			cout << R[s] << "\n";
		}

		else if (s == N - 1)
		{
			cout << L[s] << "\n";
		}

		else
		{
			if (s < t)
			{
				cout << min(R[s], L[s] + R[bestFromNode[s][0]]) << "\n";
			}
			else if (s > t)
			{
				cout << min(L[s], R[s] + L[bestFromNode[s][1]]) << "\n";
			}
		}
	}

	return 0;
}
