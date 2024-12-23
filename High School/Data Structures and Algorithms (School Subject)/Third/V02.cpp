// Hubert Jastrzębski | Satori V02 (My name is Order, Post Order) | 2023-06-08
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8554779

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        string s1, s2, s3;
        vector<int> V1(n), V2(n);
        cin >> s1;
        for (auto& v1 : V1)
            cin >> v1;
        cin >> s2;
        for (auto& v2 : V2)
            cin >> v2;
        cin >> s3;

        if (n == 1) {
            cout << V1[0] << '\n';
            continue;
        }

        if (s3 == s1) {
            for (auto& v1 : V1)
                cout << v1 << ' ';
            cout << '\n';
            continue;
        }

        if (s3 == s2) {
            for (auto& v2 : V2)
                cout << v2 << ' ';
            cout << '\n';
            continue;
        }

        if (s1 == s2) {
            if (n == 2 && s1 != "INORDER" && s3 != "INORDER")
                cout << V1[1] << ' ' << V1[0] << '\n';
            else
                cout << "ERROR\n";
            continue;
        }

        if (s2 == "PREORDER" && s1 == "INORDER") {
            swap(s1, s2);
            swap(V1, V2);
        }

        if (s1 == "PREORDER" && s2 == "INORDER") {
            unordered_map<int, int> M(n);
            for (int i = 0; i < n; i++)
                M[V2[i]] = i;

            vector<int> R;
            function<void(int, int, int)> fun = [&](int l1, int l2, int size) {
              if (size <= 0)
                  return;

              int root = M[V1[l1]];

              int size1 = root - l2;
              fun(l1 + 1, l2, size1);
              fun(l1 + size1 + 1, l2 + size1 + 1, size - size1 - 1);

              R.push_back(V2[root]);
            };

            fun(0, 0, n);

            for (auto& r : R)
                cout << r << ' ';
            cout << '\n';
            continue;
        }

        if (s2 == "INORDER" && s1 == "POSTORDER") {
            swap(s1, s2);
            swap(V1, V2);
        }

        if (s1 == "INORDER" && s2 == "POSTORDER") {
            unordered_map<int, int> M(n);
            for (int i = 0; i < n; i++)
                M[V1[i]] = i;

            vector<int> R;
            function<void(int, int, int)> fun = [&](int l1, int l2, int size) { // [l; r]
              if (size <= 0)
                  return;

              int root = M[V2[l2 + size - 1]];
              R.push_back(V1[root]);

              int size1 = root - l1;
              fun(l1, l2, size1);
              fun(l1 + size1 + 1, l2 + size1, size - size1 - 1);
            };

            fun(0, 0, n);

            for (auto& r : R)
                cout << r << ' ';
            cout << '\n';
            continue;
        }

        if (s2 == "PREORDER" && s1 == "POSTORDER") {
            swap(s1, s2);
            swap(V1, V2);
        }

        if (s1 == "PREORDER" && s2 == "POSTORDER") {
            unordered_map<int, int> M(n);
            for (int i = 0; i < n; i++)
                M[V1[i]] = i;

            bool isFull = true;
            for (int i = 0; i < n - 1; i++) {
                if (M[V2[i]] == M[V2[i + 1]] + 1)
                    isFull = false;
            }

            if (isFull) {
                M = unordered_map<int, int>(n);
                for (int i = 0; i < n; i++)
                    M[V2[i]] = i;

                vector<int> R;
                function<void(int, int, int)> fun = [&](int l1, int l2, int size) {
                  if (size <= 0)
                      return;

                  if (size == 1) {
                      R.push_back(V1[l1]);
                      return;
                  }

                  int newSize = M[V1[l1 + 1]] - l2 + 1;
                  fun(l1 + 1, l2, newSize);
                  R.push_back(V1[l1]);
                  fun(l1 + newSize + 1, l2 + newSize, size - newSize - 1);
                };

                fun(0, 0, n);

                for (auto& r : R)
                    cout << r << ' ';
                cout << '\n';
                continue;
            }
        }

        cout << "ERROR\n";
    }
}