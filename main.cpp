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

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, l, r, p) for (int i = l; i < r; i += p)

// const float PI = 3.14159265359;

using namespace std;
using ll = long long;

int main()
{
	int Q, V;
	cin >> Q >> V;
	priority_queue<int, vector<int>, less<int>> que;

	for (int q = 0; q < Q; q++)
	{
		int type;
		cin >> type;

		if (type == 1)
		{
			int t, w;
			cin >> t >> w;

			que.push(w - t);
		}
		else if (type == 2)
		{
			int t;
			cin >> t;

			if (que.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << min(V, que.top() + t) << endl;
				que.pop();
			}
		}
	}

	return 0;
}
