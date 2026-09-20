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
	ll N, M, K, X, Y;
	cin >> N >> M >> K >> X >> Y;

	vector<ll> A(N), B(M);

	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (ll i = 0; i < M; i++)
	{
		cin >> B[i];
	}

	sort(all(B));
	sort(all(A));

	for (ll i = 1; i < N; i++)
	{
		A[i] += A[i - 1];
	}

	ll ans = (ll)distance(A.begin(), upper_bound(all(A), X + Y * K));
	ll cntM = 0;

	for (ll i = 0; i < M; i++)
	{
		ll useK = (B[i] + K - 1) / K;

		if (useK <= Y)
		{
			Y -= useK;
			cntM++;

			ll ex = K * useK - B[i];
			X += ex;
		}

		auto it = upper_bound(all(A), X + Y * K);
		ll n = (ll)distance(A.begin(), it) + cntM;

		// cout << "i" << ":" << i << endl;
		// cout << "useK" << ":" << useK << endl;
		// cout << "cntN" << ":" << n - cntM << endl;
		// cout << "cntM" << ":" << cntM << endl;
		// cout << "X" << ":" << X << endl;
		// cout << "Y" << ":" << Y << endl;
		// cout << endl;

		ans = max(ans, n);

		if (useK > Y)
		{
			cout << ans << endl;
			return 0;
		}
		// cout << "," << ans << endl;
	}

	cout << ans << endl;
	return 0;
}