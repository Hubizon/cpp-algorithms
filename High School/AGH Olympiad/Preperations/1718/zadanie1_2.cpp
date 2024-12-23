// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 1) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

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

	string res = "";
	function<void(int)> fun = [&](int x) {
		if (x < 0 || res.size() > m) return;
		if (x == 0) {
			res = res + string(m - res.size(), '0');
			cout << stoll(res);
			exit(0);
		}
		for (int i = 9; i >= 1; i--) {
			res += i + '0';
			fun(x - pows[i]);
			res.pop_back();
		}
	};

	fun(n);
}
