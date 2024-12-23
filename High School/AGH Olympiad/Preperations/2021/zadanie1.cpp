// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 I (Zadanie 1) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2020_2021.pdf

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> V(n, vector<int>(n));
	for (auto& v : V)
		for (auto& vv : v)
			cin >> vv;

	int rotation = 0;
	while (m--) {
		char c;
		cin >> c;
		if (c == 'A') {
			int S;
			cin >> S;
			int r = S / 90;
			(rotation += r) %= 4;
		}
		else if (c == 'U') {
			int x, y, v;
			cin >> x >> y >> v;
			V[x][y] = v;
		}
		else {
			int x, y;
			cin >> x >> y;
			for (int r = 0; r < rotation; r++) {
				int tx = n - y - 1, ty = x;
				x = tx, y = ty;
			}
			cout << V[x][y] << '\n';
		}
	}
}
