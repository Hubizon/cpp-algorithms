// Hubert Jastrzębski | Diamentowy Indeks AGH 2019/2020 I (Zadanie 6) | 2023-03-15
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2019_2020.pdf

#include <iostream>
#include <functional>
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
	vector<vector<int>> Rows(n), Columns(n);
	for (int i = 0; i < m; i++) {
		int r, c;
		cin >> r >> c;
		P[i] = { r, c };
		Rows[r].push_back(i);
		Columns[c].push_back(i);
	}
	
	vector<int> C(n, -1);
	function<void(int, int)> DFS = [&](int r, int id) {
		if (C[r] != -1 || Rows[r].empty()) return;
		C[r] = id;
		for (auto i : Rows[r]) {
			for (auto j : Columns[P[i].second]) {
				DFS(P[j].first, id);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		DFS(i, i);
	}

	vector<int> R(n);
	for (int i = 0; i < n; i++)
		if (C[i] != -1)
			R[C[i]] += Rows[i].size();

	int res = -2;
	for (auto& r : R)
		if (r != 0)
			res += r + 1;
	cout << res;
}
