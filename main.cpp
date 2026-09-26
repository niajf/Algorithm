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
	vector<vector<int>> table;

	cin >> N;
	table.resize(floor((float)N / 10.f), vector<int>(10));
	table.push_back(vector<int>(N % 10));

	for (int i = 0; i < N; i++)
	{
		cin >> table[floor((float)i / 10.f)][i % 10];
	}

	// for (int i = 0; i < table.size(); i++)
	// {
	// 	for (int j = 0; j < table[i].size(); j++)
	// 	{
	// 		cout << table[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < table.size(); i++)
	{
		sort(all(table[i]));
		for (int j = 0; j < 10; j++)
		{
			if (i * 10 + j + 1 > N)
			{
				cout << "Yes" << endl;
				return 0;
			}

			// cout << table[i][j] << " " << i * 10 + j + 1 << endl;
			if (table[i][j] != i * 10 + j + 1)
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}
