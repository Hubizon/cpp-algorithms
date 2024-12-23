// Hubert Jastrzębski | Satori T06 (Wirusy) | 2022-10-01
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7813464

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  Node* fail = 0;
  Node* ch[2] = { 0, 0 };
  int vis = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        Node* sroot = new Node, * root = new Node{ sroot, { 0, 0 }, 0 };
        *sroot = { sroot, { root, root }, 0 };

        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            auto v = root;
            for (auto c : S) {
                c -= '0';
                if (v->ch[c] == NULL)
                    v->ch[c] = new Node;
                v = v->ch[c];
            }
            v->vis = 2;
        }

        queue<Node*> Q;
        Q.push(root);
        while (Q.size()) {
            auto u = Q.front(); Q.pop();
            if (u->fail->vis == 2)
                u->vis = 2;
            for (int i = 0; i < 2; i++) {
                auto& v = u->ch[i];
                if (v == NULL) v = u->fail->ch[i];
                else {
                    v->fail = u->fail->ch[i];
                    Q.push(v);
                }
            }
        }

        function<bool(Node*)> DFS = [&](Node* u) {
          if (u->vis == 2) return false;
          if (u->vis == 1) return true;
          u->vis = 1;
          for (int i = 0; i < 2; i++)
              if (DFS(u->ch[i]))
                  return true;
          u->vis = 2;
          return false;
        };

        cout << (DFS(root) ? "TAK\n" : "NIE\n");
