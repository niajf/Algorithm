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
	int coin100 = 0;
	int coin10 = 0;
	int coin1 = 0;
	vector<int> A;

	cin >> N;
	A.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		int useBill = ceil((float)A[i] / 1000.f);
		int ex = useBill * 1000 - A[i];

		int c100 = 0;
		int c10 = 0;
		int c1 = 0;

		c100 = floor((float)ex / 100.f);
		ex = ex - c100 * 100;

		c10 = floor((float)ex / 10.f);
		ex = ex - c10 * 10;

		c1 = ex;

		coin100 += c100;
		coin10 += c10;
		coin1 += c1;
	}

	cout << coin1 << " " << coin10 << " " << coin100 << endl;

	return 0;
}
