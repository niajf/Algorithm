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

	vector<int> P(N + 1, 0), PB(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		PB[P[i]] = i;
	}

	int *front = P.data();
	int *back = PB.data();

	while (Q--)
	{
		int type;
		cin >> type;

		if (type == 1)
		{
			int x, y;
			cin >> x >> y;

			int buff;
			buff = *(back + *(front + x));
			*(back + *(front + x)) = *(back + *(front + y));
			*(back + *(front + y)) = buff;

			buff = *(front + x);
			*(front + x) = *(front + y);
			*(front + y) = buff;
		}

		else
		{
			int *buff;
			buff = front;
			front = back;
			back = buff;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << *(front + i) << " ";
	}
	cout << endl;
}
