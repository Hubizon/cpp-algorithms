// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 I (Zadanie 5) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_i_2020_2021.pdf

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	vector<bool> IP(1e5, true);
	vector<int> P;
	for (ll i = 2; i < IP.size(); i++) {
		if (IP[i])
			P.push_back(i);
		for (ll j = i * i; j < IP.size(); j += i)
			IP[j] = false;
	}

	vector<ll> Q(n);
	for (int i = 0; i < n; i++)
		Q[i] = P[i] * P[i + d];

	unordered_map<ll, int> Q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Q[i] + Q[j] <= Q.back())
				Q2[Q[i] + Q[j]]++;
		}
	}

	int res = 0;
	for (auto q : Q) {
		for (auto q2 : Q2) {
			auto q3 = Q2.find(q - q2.first);
			if (q3 != Q2.end())
				res += q2.second * q3->second;
		}
	}

	cout << res;
}
