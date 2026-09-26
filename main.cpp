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

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, l, r, p) for (int i = l; i < r; i += p)

const float PI = 3.14159265359;

using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;

	vector<ll> A, B, ans;
	A.resize(N);
	B.resize(N);
	ans.resize(N, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	bool ok = false;
	for (int i = 0; i < N; i++)
	{
		A[i] -= B[i];

		if (A[i] > 0)
		{
			ok = true;
			ans[i] = 1000000000000000000;
			// cout << ans[i] << endl;
		}
	}

	if (ok)
	{
		cout << "Yes" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}
