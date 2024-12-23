// Hubert Jastrzębski | Satori PAL (Palindromy) | 2022-07-23
// https://satori.tcs.uj.edu.pl/contest/1870276/problems/1871204

#include <iostream>
#include <array>

using namespace std;

struct Node {
  int size;
  Node* link;
  array<Node*, 30> children;

  Node(int sizee, Node* linkk) {
      size = sizee;
      link = linkk;
      children.fill(NULL);
  }

  ~Node() {
      for (auto& child : children)
          delete child;
  }
};

struct Tree {
  int res = 0;

  string S = "";
  Node *prev;
  Node *node1, *node0;

  Tree() {
      node1 = new Node(-1, NULL);
      node0 = new Node(0, node1);
      prev = node0;
  }

  void add(char c) {
      S += c; c-= 'a';

      // znajdywanie ostatniego palindromu, który da się wydłużyć o tą literkę
      Node* p = prev;
      while ((int)S.size() - p->size - 2 < 0 || S[(int)S.size() - p->size - 2] != S.back())
          p = p->link;

      // jeśli taki palindrom już istnieje, zmień prev i wyjdź
      if (p->children[c] != NULL) {
          prev = p->children[c];
          return;
      }

      // w przeciwnym wypadku stwórz nowe dziecko i zmień prev
      Node* child = new Node(p->size + 2, NULL);
      p->children[c] = child;
      prev = child;
      res++;

      // jeśli palindrom jest jednoliterowy
      if (p->size == -1) {
          child->link = node0;
          return;
      }

      // znajdź link
      p = p->link;
      while (S[S.size() - p->size - 2] != S.back()) {
          p = p->link;
      }

      child->link = p->children[c];
  }

  ~Tree() {
      delete node0;
      delete node1;
  }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        string S;
        cin >> S;

        Tree tree = Tree();

        for (auto& c : S) tree.add(c);

        cout << tree.res << '\n';
    }
}