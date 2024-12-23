// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 6) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	vector<ll> S;
	for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
		ll sum = 0;
		for (int i = 0; i < n; i++)
			if ((bitmask >> i) & 1)
				sum += V[i];
		S.push_back(sum);
	}

	sort(S.begin(), S.end());
	S.resize(unique(S.begin(), S.end()) - S.begin());
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i + 1] != S[i] + 1) {
			cout << S[i] + 1;
			return 0;
		}
	}

	cout << S.back() + 1;
}
