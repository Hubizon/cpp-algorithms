// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (Last Digit) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	function<int(int, int)> fun = [&](int x, int cnt) -> int {
		if (x < 0) return -1;
		if (cnt == 1) {
			if (x <= 9) 
				return x;
			return -1;
		}
		for (int i = 0; i <= 9; i++) {
			int t = stoi(string(cnt, i + '0'));
			int y = fun(x - t, cnt - 1);
			if (y != -1)
				return i * pow(10, cnt - 1) + y;
		}
		return -1;
	};

	int m = to_string(n).size();
	cout << fun(n, m);
}
