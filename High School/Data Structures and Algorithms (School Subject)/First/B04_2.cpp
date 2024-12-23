// Hubert Jastrzębski | Satori B04 (Mnożenie) | 2022-08-03
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6552050

#include <iostream>
#include <functional>
#include <algorithm>
#include <complex>
#include <vector>
#include <string>

using namespace std;

typedef vector<complex<double>> VCD;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        string s1, s2;
        cin >> s1 >> s2;
        s1 = string(s1.rbegin(), s1.rend());
        s2 = string(s2.rbegin(), s2.rend());

        bool isMinus = ((s1.back() == '-') ^ (s2.back() == '-'));
        if (s1.back() == '-') s1.pop_back();
        if (s2.back() == '-') s2.pop_back();

        int L = 1;
        while (s1.size() + s2.size() >= L) L *= 2;

        function<void(VCD&, const VCD&, bool)> FFT = [&](VCD& A, const VCD& W, bool invert) {
          int n = A.size();
          if (n == 1) return;

          VCD A0(n / 2), A1(n / 2), WW(n / 2);
          for (int i = 0; i < n / 2; i++) {
              A0[i] = A[2 * i];
              A1[i] = A[2 * i + 1];
              WW[i] = W[2 * i];
          }

          FFT(A0, WW, invert), FFT(A1, WW, invert);

          for (int j = 0; j < n / 2; j++) {
              A[j] = A0[j] + W[j] * A1[j];
              A[j + n / 2] = A0[j] - W[j] * A1[j];
              if (invert) A[j] /= 2, A[j + n / 2] /= 2;
          }
        };

        VCD A(L), B(L), W(L);
        for (int i = 0; i < s1.size(); i++) A[i] = s1[i] - '0';
        for (int i = 0; i < s2.size(); i++) B[i] = s2[i] - '0';

        for (int i = 0; i < L; i++)
            W[i] = polar(1.0, 2 * M_PI * i / L);
        FFT(A, W, false), FFT(B, W, false);

        VCD C(L);
        for (int i = 0; i < L; i++) C[i] = A[i] * B[i];

        for (int i = 0; i < L; i++)
            W[i] = polar(1.0, -2 * M_PI * i / L);
        FFT(C, W, true);

        vector<long long> R(L);
        for (int i = 0; i < L; i++) R[i] = (C[i].real() + 0.5);

        for (int i = 0, a = 0; i < L; i++) {
            R[i] += a;
            a = R[i] / 10;
            R[i] %= 10;
        }

        while (R.size() && R.back() == 0) R.pop_back();
        if (R.empty()) cout << 0;
        else if (isMinus) cout << '-';
        for (int i = R.size() - 1; i >= 0; i--)
            cout << R[i];
        cout << '\n';
    }
}