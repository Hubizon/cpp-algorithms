// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 I (Zadanie 4) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2020_2021.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <set>

using namespace std;

constexpr int INF = 1e9;

bool isPrime(int x) {
	if (x % 2 == 0 || x <= 1) return false;
	for (long long i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, u, k;
	//cin >> l >> u >> k;
	
	long long V = 0;
	vector<int> to1;
	function<void(int, int)> fun = [&](int S, int cnt) {
		if (cnt >= 9 || S > 100) return;
		if (S == 100 || S == 10 || S == 1)
			to1.push_back(V);
		for (int i = 0; i <= 9; i++) {
			V *= 10, V += i;
			fun(S + i * i, cnt + 1);
			V /= 10;
		}
	};

	fun(0, 0);

	set<int> R;
	for (auto x : to1) {
		if (isPrime(x))
			R.insert(x);
	}

	cout << "";
}
