// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (The OR Game) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, g;
	cin >> n >> g;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	vector<int> P;
	vector<int> cnt(n);
	function<void(int, int)> newton = [&](int k, int offset) {
		if (k == 0) {
			int xorall = 0;
			for (auto p : P)
				xorall ^= V[p];
			if (xorall == g)
				for (auto p : P)
					cnt[p]++;
			return;
		}
		for (int i = offset; i < n - k + 1; i++) {
			P.push_back(i);
			newton(k - 1, offset + 1);
			P.pop_back();
		}
	};

	int k = 1, res = 0;
	while (true) {
		if (n < k)
			break;
		newton(k, 0);
		auto x = max_element(cnt.begin(), cnt.end());
		if (*x == 0)
			k++;
		else {
			int pos = x - cnt.begin();
			vector<int> newV;
			for (int i = 0; i < n; i++)
				if (i != pos)
					newV.push_back(V[i]);
			V = newV;
			cnt = vector<int>(--n);
			res++;
		}
	}

	cout << res;
}
