// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (Odd Divisor) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int t = i;
		while (t % 2 == 0)
			t /= 2;
		res += t;
	}

	cout << res;
}
