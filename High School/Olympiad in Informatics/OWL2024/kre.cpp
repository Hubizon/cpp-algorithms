// Hubert Jastrzębski | PREOI / OWL 2024 (Krecik) | 2024-02-02
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/kre/

#include "krelib.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

/*typedef pair<int, int> PI;

int N, K, L;
int root;
vector<PI> edges;
vector<int> parent;

int questions;

void error(const string& message) { cout << "Blad: " << message << endl; exit(0); }

void start(int& x, int& y)
{
    cin >> K >> L;
    x = K;
    y = L;
    N = (1 << (K + 1)) - 1;
    parent.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        int v;
        cin >> v;
        if (v != 0)
        {
            edges.push_back(PI(i, v));
            parent[i] = v;
        }
        else
            root = v;
    }
    questions = 0;
}

bool query(int a, int b, int c)
{
    if (a < 1 || a > N) error("Zly numer wierzcholka!");
    if (b < 1 || b > N) error("Zly numer wierzcholka!");
    if (c < 1 || c > N) error("Zly numer wierzcholka!");
    ++questions;
    if (questions > L) error("Za duzo pytan!");
    vector<int> patha = { a }, pathc = { c };
    int wa = a, wc = c;
    while (patha.back() != root) { wa = parent[wa]; patha.push_back(wa); }
    while (pathc.back() != root) { wc = parent[wc]; pathc.push_back(wc); }
    reverse(patha.begin(), patha.end());
    reverse(pathc.begin(), pathc.end());
    while (patha.size() < pathc.size()) patha.push_back(a);
    while (patha.size() > pathc.size()) pathc.push_back(c);
    while (true) {
        if (b == patha.back() || b == pathc.back()) { return true; }
        if (patha.back() == pathc.back()) break;
        patha.pop_back();
        pathc.pop_back();
    }
    return false;
}

bool cmp_vectors(vector<PI> A, vector<PI> B) {
    for (auto& p : A)
        if (p.first > p.second)
            swap(p.first, p.second);
    for (auto& p : B)
        if (p.first > p.second)
            swap(p.first, p.second);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;
}

void answer(vector<PI> A)
{
    if (A.size() != edges.size())
        error("Zly rozmiar wektora!");
    if (!cmp_vectors(A, edges))
        error("Drzewo sie nie zgadza!");
    cout << "Program zgadl prawidlowo w " << questions << " pytaniach." << endl;
    exit(0);
}*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    start(K, L);
    int n = (1 << (K + 1)) - 1;

    auto findAll = [&](int a, const vector<int>& toA = { }) {
      int cnt = 0;
      vector<bool> A(n + 1);
      if (toA.empty())
          fill(A.begin(), A.end(), true);
      else {
          cnt = n;
          for (auto& toa : toA) {
              A[toa] = true; cnt--;
          }
      }

      A[a] = false; cnt++;

      auto find = [&]() {
        int x = -1;
        for (int y = 1; y <= n; y++)
            if (A[y] && (x == -1 || query(a, y, x)))
                x = y;
        return x;
      };

      vector<vector<int>> Sub;
      while (cnt != n) {
          int x = find();
          A[x] = false; cnt++;
          Sub.push_back({ x });
          for (int y = 1; y <= n; y++) {
              if (A[y] && query(a, x, y)) {
                  Sub.back().push_back(y);
                  A[y] = false; cnt++;
              }
          }
      }

      return Sub;
    };

    int root = 1;
    vector<vector<int>> Sub = findAll(1);
    while (Sub.size() != 2) {
        int maxS = 0, pos = 0;
        for (int i = 0; i < Sub.size(); i++) {
            if (Sub[i].size() > maxS) {
                maxS = Sub[i].size();
                pos = i;
            }
        }
        root = Sub[pos][0];
        Sub = findAll(root);
    }

    vector<pair<int, int>> E;
    function<void(vector<int>, int)> fun = [&](vector<int> T, int p) {
      int root = T[0];
      E.push_back({ p, root });
      if (T.size() != 1) {
          vector<vector<int>> Sub = findAll(root, T);
          fun(Sub[0], root);
          fun(Sub[1], root);
      }
    };

    fun(Sub[0], root);
    fun(Sub[1], root);

    //for (auto& [a, b] : E)
    //    cout << a << ' ' << b << '\n';
    answer(E);
}