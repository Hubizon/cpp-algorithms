// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 5) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

bool isPrime(ll x) {
	if (x <= 1 || x % 2 == 0)
		return false;
	for (ll i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int n = S.size();

	vector<vector<pair<int, ll>>> V(n);
	for (int i = 0; i < n; i++) {
		string ts = "";
		for (int j = i; j < min(n, i + 32); j++) {
			ts += S[j];
			ll x = stoll(ts, nullptr, 2);
			if (isPrime(x))
				V[j].push_back({ i, x});
		}
	}

	vector<vector<pair<ll, int>>> DP(n);
	for (int i = 0; i < n; i++) {
		for (auto& v : V[i]) {
			int first = v.first;
			ll x = v.second;
			if (first == 0)
				DP[i].push_back({ x, 1 });
			else {
				int tr = 0;
				for (auto dp : DP[first - 1]) {
					if (dp.first < x)
						tr += dp.second;
				}
				if (tr != 0)
					DP[i].push_back({ x, tr });
			}
		}
	}

	int res = 0;
	for (auto dp : DP.back())
		res += dp.second;

	cout << res;
}
