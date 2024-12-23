// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 3) | 2023-03-18
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string hPow(string S) {
	int n = S.size();
	vector<int> V(2 * n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			V[i + j + 1] += (S[i] - '0') * (S[j] - '0');
	for (int i = V.size() - 1; i > 0; i--) {
		V[i - 1] += V[i] / 10;
		V[i] %= 10;
	}

	string res;
	if (V.front() != 0)
		res = V.front() + '0';
	for (int i = 1; i < V.size(); i++)
		res += V[i] + '0';
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll m, n;
	cin >> m >> n;

	int sq = sqrt(m);
	string S = to_string(sq);
	int sqsize = S.size(), res = 0;
	for (int i = 0; i < n; i++) {
		S += '0';
		for (int i = 1; i <= 9; i++) {
			S.back() = i + '0';
			string nS = hPow(S);
			int dec = nS.size() - 2 * (S.size() - sqsize);
			if (stoi(nS.substr(0, dec)) >= m) {
				S.back()--;
				break;
			}
		}
		res += S.back() - '0';
	}

	cout << res;
}
