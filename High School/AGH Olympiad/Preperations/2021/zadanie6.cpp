// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 I (Zadanie 6) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2020_2021.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<bool>> M(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			M[i][j] = (c == '#');
		}
	}

	vector<vector<int>> vis(n, vector<int>(m));
	function<void(int, int, int)> DFS = [&](int i, int j, int x) {
		if (vis[i][j]) return;
		vis[i][j] = x;
		if (i != 0 && !M[i - 1][j])
			DFS(i - 1, j, x);
		if (i != n - 1 && !M[i + 1][j])
			DFS(i + 1, j, x);
		if (j != 0 && !M[i][j - 1])
			DFS(i, j - 1, x);
		if (j != m - 1 && !M[i][j + 1])
			DFS(i, j + 1, x);
	};

	DFS(0, 0, 1);
	DFS(n - 1, m - 1, -1);

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j]) {
				bool is1 = false, ism1 = false;
				vector<pair<int, int>> Neig;
				if (i != 0)
					Neig.push_back({ i - 1, j });
				if (i != n - 1)
					Neig.push_back({ i + 1, j });
				if (j != 0)
					Neig.push_back({ i, j - 1 });
				if (j != m - 1)
					Neig.push_back({ i, j + 1 });
				for (auto neig : Neig) {
					if (vis[neig.first][neig.second] == 1)
						is1 = true;
					else if (vis[neig.first][neig.second] == -1)
						ism1 = true;
				}
				if (is1 && ism1)
					res++;
			}
		}
	}

	cout << res;
}
