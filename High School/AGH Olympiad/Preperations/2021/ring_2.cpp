// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (Ring) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int n = S.size();

	vector<bool> IP(n, true);
	vector<int> P;
	for (int i = 2; i < IP.size(); i++) {
		if (IP[i]) P.push_back(i);
		for (int j = i * i; j < IP.size(); j += i)
			IP[j] = false;
	}

	string res = string(n, 'z');
	for (int o = 0; o < n; o++) {
		for (auto p : P) {
			string T;
			int pos = o;
			for (int i = 0; i < n; i++) {
				T += S[pos];
				(pos += p) %= n;
			}
			res = min(res, T);
		}
	}

	cout << res;
}
