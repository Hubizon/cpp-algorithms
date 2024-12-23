// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 I (Zadanie 2) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2020_2021.pdf

#include <iostream>
#include <functional>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	priority_queue<int> Q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}

	while (k--) {
		auto q = Q.top(); Q.pop();
		Q.push(q / 2);
	}

	int res = 0;
	while (Q.size())
		res += Q.top(), Q.pop();

	cout << res;
}
