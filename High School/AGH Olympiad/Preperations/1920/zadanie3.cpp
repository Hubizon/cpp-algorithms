// Hubert Jastrzębski | Diamentowy Indeks AGH 2019/2020 I (Zadanie 3) | 2023-03-15
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2019_2020.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	int fnotm = INF, snotm = INF;
	for (int i = 0; i < n; i++) {
		if (V[i] != -1) {
			if (fnotm == INF)
				fnotm = i;
			else
				snotm = i;
		}
	}

	if (fnotm == INF) {
		cout << 0;
		return 0;
	}

	if (snotm == INF) {
		cout << V[fnotm];
		return 0;
	}

	int res = INF;
	const int M = 10;
	for (int m = 0; m <= 10; m++) {
		vector<int> A(n);
		A[fnotm] = m;
		int xorall = m;
		for (int i = 0; i < n; i++) {
			if (V[i] != -1 && i != fnotm) {
				A[i] = m ^ V[fnotm] ^ V[i];
				xorall ^= A[i];
			}
		}

		int xormo = V[fnotm] ^ m ^ xorall;
		xorall ^= xormo;
		int tr = 0;
		for (int i = 0; i < n; i++) {
			if (V[i] != -1) {
				if ((xorall ^ A[i]) != V[i])
					tr = INF;
				tr += A[i];
			}
		}
		res = min(res, tr + xormo);
	}

	cout << res;
}