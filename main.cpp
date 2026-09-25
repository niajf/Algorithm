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
	string S;
	cin >> S;

	string ans(2 * S.size() - 1, 'o');
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i % 2 == 0)
		{
			ans[i] = S[cnt];
			cnt++;
		}
	}

	cout << ans << endl;

	return 0;
}
