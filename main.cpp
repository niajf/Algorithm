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
	int N, K;
	vector<int> vNumPerClass;

	cin >> N >> K;
	vNumPerClass.resize(K, 0);

	// クラスごとに何人所属してるか
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vNumPerClass[n - 1]++;
	}

	sort(all(vNumPerClass));
	int iMaxNum = vNumPerClass[K - 1];
	// cout << iMaxNum << endl;

	auto iter = lower_bound(all(vNumPerClass), iMaxNum - 1);
	if (iter != vNumPerClass.end())
	{
		// cout << *iter << endl;
		cout << distance(iter, vNumPerClass.end()) << endl;
	}

	return 0;
}
