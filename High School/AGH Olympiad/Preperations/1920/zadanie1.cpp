// Hubert Jastrzębski | Diamentowy Indeks AGH 2019/2020 I (Zadanie 1) | 2023-03-14
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2019_2020.pdf

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, DL, AL;
	cin >> N >> DL >> AL;

	int res = 0, r = 0;
	for (int i = 0; i < N; i++) {
		if (r > DL) {
			r -= DL, res++;
			continue;
		}
		int t = (DL - r) % AL;
		if (t > 0)
			res++, r = AL - t;
		else r = 0;
	}

	cout << res;
}