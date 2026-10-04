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
	ll N;
	cin >> N;

	priority_queue<ll, vector<ll>, greater<ll>> positiveQue;
	priority_queue<ll, vector<ll>, less<ll>> negativeQue;

	for (ll i = 0; i < N; i++)
	{
		ll a;
		cin >> a;

		if (a >= 0)
			positiveQue.push(a);
		else
			negativeQue.push(a);
	}

	ll length = 0;
	ll pos = 0;
	for (ll i = 0; i < N; i++)
	{
		ll posLength = LLONG_MAX;
		ll negLength = LLONG_MAX;

		if (!positiveQue.empty())
			posLength = abs(pos - positiveQue.top());

		if (!negativeQue.empty())
			negLength = abs(pos - negativeQue.top());

		// cout << positiveQue.top() << " " << negativeQue.top() << " ";

		if (posLength < negLength)
		{
			// cout << "Pos ";
			pos = positiveQue.top();
			length += posLength;
			positiveQue.pop();
		}
		else if (posLength > negLength)
		{
			// cout << "Neg ";
			pos = negativeQue.top();
			length += negLength;
			negativeQue.pop();
		}

		else if (posLength == negLength)
		{
			if (positiveQue.top() < negativeQue.top())
			{
				// cout << "Pos ";
				pos = positiveQue.top();
				length += posLength;
				positiveQue.pop();
			}

			else
			{
				// cout << "Neg ";
				pos = negativeQue.top();
				length += negLength;
				negativeQue.pop();
			}
		}

		// cout << pos << endl;
	}

	cout << length << endl;
	return 0;
}
