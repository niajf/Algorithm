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

int N, K;

void dfs(int index, vector<int> a)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i * a[i];
	}

	if (index > N - 1)
	{
		if ((K - sum) % N == 0)
		{
			// cout << index << " " << sum << endl;
			for (int i = 1; i < N; i++)
			{
				cout << a[i] << " ";
			}
			cout << (K - sum) / N << endl;
		}
	}
	else
	{
		for (int i = 0; i < (K - sum) / (index) + 1; i++)
		{
			dfs(index + 1, a);
			a[index]++;
		}
	}
}

int main()
{
	vector<int> A;

	cin >> N >> K;
	A.resize(N + 1, 0);

	dfs(1, A);

	return 0;
}
