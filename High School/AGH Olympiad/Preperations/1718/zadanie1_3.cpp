// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 1) | 2023-03-19
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	int m = to_string(n).size();
	vector<ll> pows(10);
	for (int i = 0; i < 10; i++)
		pows[i] = pow(i, m);

	const vector<int> V = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	ll sum = 0;
	ll combination = 0;

	function<void(int, int)> newton = [&](int k, int offset) {
		if (k == 0) {
			if (sum == n) {
				cout << combination;
				exit(0);
			}
			return;
		}
		for (int i = offset; i < V.size(); i++) {
			combination = 10 * combination + V[i];
			sum += pows[V[i]];

			newton(k - 1, i);

			combination /= 10;
			sum -= pows[V[i]];
		}
	};

	newton(m, 0);
}
