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
	int N, S;
	ll L;
	vector<ll> A;
	vector<vector<ll>> B;

	cin >> N >> S >> L;
	A.resize(N - 1);
	B.resize(N, vector<ll>(N, 0));

	for (int i = 0; i < N - 1; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{

		for (int j = i - 1; j >= 0; j--)
		{
			B[i][j] = B[i][j + 1] + A[j];
		}

		for (int j = i + 1; j < N; j++)
		{
			B[i][j] = B[i][j - 1] + A[j - 1];
		}
	}

	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	{
	// 		cout << B[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// 訪れる街の最大値
	int ans = 0;

	// 左側に探索
	for (int i = S - 1; i >= 0; i--)
	{
		int townNum = S - i;
		ll length = B[S - 1][i];

		// cout << townNum << endl;
		// cout << length << endl;

		if (length > L)
			continue;

		auto ptr = upper_bound(B[i].begin() + i, B[i].end(), L - length);
		--ptr;
		// cout << "*ptr: " << *ptr << endl;

		int dis = distance(B[i].begin(), ptr) - (S - 1);
		if (dis > 0)
			townNum += dis;

		ans = max(ans, townNum);

		// cout << townNum << endl;
		// cout << endl;
	}

	for (int i = S - 1; i < N; i++)
	{
		int townNum = i - S + 2;
		ll length = B[S - 1][i];

		// cout << "start town: " << i << endl;
		// cout << townNum << endl;
		// cout << length << endl;

		if (length > L)
			continue;

		int maxTownIdx = -1;
		for (int j = i; j >= 0; j--)
		{
			if (B[i][j] + length > L)
			{
				break;
			}

			maxTownIdx = j;
		}

		// cout << "town: " << B[i][maxTownIdx] << endl;
		int dis = S - 1 - maxTownIdx;
		if (dis > 0)
			townNum += dis;

		ans = max(ans, townNum);

		// cout << townNum << endl;
		// cout << endl;
	}

	cout << ans << endl;

	return 0;
}
