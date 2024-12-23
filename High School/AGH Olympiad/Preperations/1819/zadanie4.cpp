// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 4) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <array>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> V(n);
	vector<pair<int, int>> Pos;
	for (auto& v : V) {
		cin >> v.first >> v.second;
		Pos.push_back({ v.first - m, v.second - m });
		Pos.push_back({ v.first - m, v.second });
		Pos.push_back({ v.first, v.second - m });
		Pos.push_back({ v.first, v.second });
	}
	
	int res = 0;
	for (auto& pos : Pos) {
		int tr = 0;
		for (auto& v : V) {
			if (v.first >= pos.first && v.first <= pos.first + m &&
				v.second >= pos.second && v.second <= pos.second + m)
				tr++;
		}
		res = max(res, tr);
	}

	cout << res;
}
