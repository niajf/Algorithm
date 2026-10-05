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

	int ans = 0;
	vector<int> A(N, 0);
	set<int> nonZeroIndex;

	while (Q--)
	{
		int type;
		cin >> type;

		if (type == 1)
		{
			int x;
			cin >> x;
			x--;

			if (!nonZeroIndex.count(x))
				nonZeroIndex.insert(x);

			ans ^= A[x];
			A[x]++;
			ans ^= A[x];
		}

		else
		{
			ans = 0;
			auto iter = nonZeroIndex.begin();
			while (iter != nonZeroIndex.end())
			{
				A[*iter]--;
				ans ^= A[*iter];

				if (A[*iter] == 0)
					iter = nonZeroIndex.erase(iter);
				else
					++iter;
			}
		}

		// auto iter = nonZeroIndex.begin();
		// while (iter != nonZeroIndex.end())
		// {
		// 	cout << *iter << " ";
		// 	++iter;
		// }

		cout << ans << endl;
	}
}
