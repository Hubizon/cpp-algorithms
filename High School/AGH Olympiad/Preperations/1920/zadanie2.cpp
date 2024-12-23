// Hubert Jastrzębski | Diamentowy Indeks AGH 2019/2020 I (Zadanie 2) | 2023-03-14
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2019_2020.pdf

#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std;

bool isPrime(const int x) {
	if (x <= 1 || x % 2 == 0)
		return false;
	for (long long p = 3; p * p <= x; p += 2)
		if (x % p == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	vector<string> M(R);
	for (auto& m : M)
		cin >> m;

	

	int res = 0;
	function<void(string, int)> fun = [&](string temp, int pos) {
		if (pos == R) {
			res += isPrime(stoi(temp));
			return;
		}
		
		for (int i = 0; i < C; i++) {
			temp[pos] = M[pos][i];
			fun(temp, pos + 1);
		}
	};

	fun(string(R, '0'), 0);

	cout << res;
}