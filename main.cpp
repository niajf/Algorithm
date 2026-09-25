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

vector<bool> isprime;
vector<ll> Era(int n)
{
	isprime.resize(n, true);
	vector<ll> res;
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i < n; ++i)
		isprime[i] = true;
	for (ll i = 2; i < n; ++i)
	{
		if (isprime[i])
		{
			res.push_back(i);
			for (ll j = i * 2; j < n; j += i)
				isprime[j] = false;
		}
	}
	return res;
}

bool resolve(string n, string s)
{
	if (n.size() != s.size())
		return false;

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				if (n[i] != n[j])
					return false;
			}

			if (n[i] == n[j])
			{
				if (s[i] != s[j])
					return false;
			}
		}
	}

	return true;
}

int main()
{

	string S;
	cin >> S;

	string numStr(S.size(), '9');
	int numInt = stoi(numStr);
	vector<ll> prime = Era(numInt);

	for (int i = 0; i < prime.size(); i++)
	{
		if (resolve(to_string(prime[i]), S))
		{
			cout << prime[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
