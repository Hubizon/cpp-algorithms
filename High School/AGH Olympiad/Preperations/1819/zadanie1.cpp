// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 1) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	int res = 1;
	for (ll i = 2; i <= n; i++) {
		ll j = i % 10;
		if (j == 0) continue;
		res *= j;
		while (res % 10 == 0)
			res /= 10;
		res %= 10;
	}

	cout << res;
}
