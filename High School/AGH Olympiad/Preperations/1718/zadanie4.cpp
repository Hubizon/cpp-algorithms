// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 4) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <cmath>
#include <set>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool IP[(int)(1e6 + 10)];
	memset(IP, true, sizeof(IP));
	vector<ll> P;
	for (ll i = 2; i < sizeof(IP); i++) {
		if (IP[i]) {
			P.push_back(i);
			for (ll j = i * i; j < sizeof(IP); j += i)
				IP[j] = false;
		}
	}

	int n;
	cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		for (auto& p : P) {
			if (p > t || i + p >= n) break;
			if (t % p == 0)
				G[i].push_back(i + p);
		}
	}

	vector<int> dist(n, INF); dist[0] = 0;
	queue<int> Q; Q.push(0);
	while (Q.size()) {
		auto u = Q.front(); Q.pop();
		for (auto v : G[u]) {
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
			if (v == n - 1) {
				cout << dist[v];
				return 0;
			}
		}
	}

	cout << -1;
}
