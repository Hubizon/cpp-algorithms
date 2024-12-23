// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 5) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <functional>
#include <string>
#include <array>

using namespace std;

typedef long long ll;

string decToBin(ll x) {
	string res;
	while (x) {
		res += '0' + (x % 2);
		x /= 2;
	}
	return string(res.rbegin(), res.rend());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	string S = decToBin(n);
	int ns = S.size();

	ll res = (1LL << max((ll)ns, k)) - 1;
	for (int i = 0; i < ns - k; i++) {
		string tS = S.substr(0, i) + string(k, '1') + string(S.size() - k - i, '0');
		ll x = stoll(tS, nullptr, 2);
		if (x >= n)
			res = min(res, x);
	}

	cout << res;
}
