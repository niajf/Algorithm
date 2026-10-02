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
	int H, W, K;
	cin >> H >> W >> K;

	vector<vector<char>> table(H, vector<char>(W));

	vector<int> safeColIndex;
	vector<int> safeRowIndex;
	for (int i = 0; i < H; i++)
	{
		bool isSafe = true;
		for (int j = 0; j < W; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == '#')
				isSafe = false;
		}

		if (isSafe)
			safeColIndex.push_back(i);
	}

	for (int i = 0; i < W; i++)
	{
		bool isSafe = true;
		for (int j = 0; j < H; j++)
		{
			if (table[j][i] == '#')
				isSafe = false;
		}

		if (isSafe)
			safeRowIndex.push_back(i);
	}

	// for (auto n : safeColIndex)
	// {
	// 	cout << n << " ";
	// }
	// cout << endl;

	// for (auto n : safeRowIndex)
	// {
	// 	cout << n << " ";
	// }
	// cout << endl;

	using qType = pair<int, pair<int, int>>;
	vector<vector<int>> costFromSafe(H, vector<int>(W, H + W));
	priority_queue<qType, vector<qType>, greater<qType>> que;

	vector<int> di = {-1, 0, 1, 0};
	vector<int> dj = {0, 1, 0, -1};

	for (auto h : safeColIndex)
	{
		for (auto w : safeRowIndex)
		{
			que.push({0, {h, w}});
		}
	}

	int ans = 0;
	while (!que.empty())
	{
		auto node = que.top();
		que.pop();

		int cost = node.first;
		pair<int, int> pos = node.second;

		if (cost > K)
			break;

		if (costFromSafe[pos.first][pos.second] != H + W)
		{
			continue;
		}
		else
		{
			costFromSafe[pos.first][pos.second] = cost;
			ans++;
		}

		for (int k = 0; k < 4; k++)
		{
			int ni = pos.first + di[k];
			int nj = pos.second + dj[k];

			if (!(0 <= ni && ni < H && 0 <= nj && nj < W))
				continue;

			if (table[ni][nj] != '.')
				continue;

			que.push({cost + 1, {ni, nj}});
		}
	}

	cout << ans << endl;

	return 0;
}
