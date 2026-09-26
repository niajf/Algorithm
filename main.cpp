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
	int N, Q;
	cin >> N >> Q;

	vector<int> P, A;
	set<int> st;
	map<int, int> mp;
	P.resize(N);
	A.resize(Q);

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
		st.insert(P[i]);
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < Q; i++)
	{
		if (st.count(A[i]))
		{
			P.push_back(A[i]);
			mp[A[i]]++;
		}
	}

	for (int i = 0; i < P.size(); i++)
	{
		if (mp[P[i]] > 0)
		{
			mp[P[i]]--;
		}
		else
		{
			cout << P[i] << " ";
		}
	}

	cout << endl;
	return 0;
}
