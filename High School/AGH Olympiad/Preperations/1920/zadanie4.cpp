// Hubert Jastrzębski | Diamentowy Indeks AGH 2019/2020 I (Zadanie 4) | 2023-03-15
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2019_2020.pdf

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> P(m);
	for (auto& p : P)
		cin >> p.first >> p.second;
	P.push_back({ 0, 0 });
	P.push_back({ n - 1, n - 1 });
	
	auto dist = [&](int a, int b) {
		return max(abs(P[a].first - P[b].first), abs(P[a].second - P[b].second));
	};

	/*
	vector<pair<int, int>> V = { { m, m + 1 } };
	int res = dist(m, m + 1);
	for (int i = 0; i < m; i++) {
		int minCost = INF;
		for (auto v : V)
			minCost = min(minCost, dist(v.first, i) + dist(i, v.second) - dist(v.first, v.second));
		res += minCost;

		vector<pair<int, int>> NV;
		for (auto v : V) {
			if (minCost == dist(v.first, i) + dist(i, v.second) - dist(v.first, v.second)) {
				NV.push_back({ v.first, i });
				NV.push_back({ i, v.second });
				minCost = INF;
			}
			else
				NV.push_back(v);
		}
			
		
		V = NV;
	}

	cout << res;*/

	int res = INF;

	do {
		int t = dist(m, 0) + dist(m - 1, m + 1);
		for (int i = 0; i < m - 1; i++)
			t += dist(i, i + 1);
		res = min(res, t);
	} while (next_permutation(P.begin(), P.begin() + m));

	cout << res;
}
