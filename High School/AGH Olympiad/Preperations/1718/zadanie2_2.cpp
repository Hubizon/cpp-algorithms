// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 2) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> F = { 1, 1 };
	while (F.back() < 1e7)
		F.push_back(*F.rbegin() + *++F.rbegin());

	vector<bool> V(1e7);
	for (int i = 0; i < F.size(); i++) {
		int sum = 0;
		for (int j = i; j < F.size(); j++) {
			sum += F[j];
			if (sum >= V.size()) break;
			V[sum] = true;
		}
	}

	for (int i = n + 1; i < V.size(); i++) {
		if (!V[i]) {
			cout << i;
			return 0;
		}
	}
}
