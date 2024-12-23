// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (Największy substring) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	auto s = max_element(S.begin(), S.end());
	while (s != S.end()) {
		cout << *s;
		s = max_element(s + 1, S.end());
	}
}
