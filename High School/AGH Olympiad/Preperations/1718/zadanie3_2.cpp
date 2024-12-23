// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 3) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<bool>> V(n, vector<bool>(10));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto c : s)
			V[i][c - '0'] = true;
	}

	int res = 0;
	for (int c = 0; c <= 9; c++) {
		int tr = 0;
		for (int i = 0; i < n; i++) {
			if (V[i][c]) tr++;
			else tr = 0;
			res = max(res, tr);
		}
	}
	cout << res;
}
