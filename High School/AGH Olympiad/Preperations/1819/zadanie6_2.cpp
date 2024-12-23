// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 6) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int n = S.size();

	string R;
	stack<pair<int, int>> Pos;
	for (int i = 0; i < n; i++) {
		auto s = S[i];
		if (s == '[') 
			Pos.push({ i++, R.size() });
		else if (s == ']') {
			auto pos = Pos.top(); Pos.pop();
			int cnt = S[pos.first + 1] - '0';
			string toR = R.substr(pos.second, R.size() - pos.second);
			while (--cnt)
				R += toR;
		}
		else 
			R += s;
	}

	cout << R;
}
