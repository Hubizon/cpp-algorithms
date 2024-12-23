// Hubert Jastrzębski | Satori V03 (Zabawa karnawałowa) | 2023-06-05
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8562984

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Wagon {
  Wagon* N[2] = { this, this };
  string name;

  Wagon(const string& name) : name(name) {
      //n0->N[n0->N[1] == n1] = this;
      //n1->N[n1->N[1] == n0] = this;
  }

  ~Wagon() {
      //delete[] N;
  };
};

struct Train {
  Wagon* head; // head->N[0] - pierwszy, head->N[1] - ostatni
  string name;

  Train(const string& name, const string& wagonName) : head(new Wagon("")), name(name) {
      pushFront(new Wagon(wagonName));
  }

  void pushFront(Wagon* wagon) {
      wagon->N[0] = head; wagon->N[1] = head->N[0];
      head->N[0]->N[head->N[0]->N[1] == head] = wagon;
      head->N[0] = wagon;
  }

  void pushBack(Wagon* wagon) {
      wagon->N[0] = head; wagon->N[1] = head->N[1];
      head->N[1]->N[head->N[1]->N[1] == head] = wagon;
      head->N[1] = wagon;
  }

  ~Train() {
      clear();
      delete head;
  }

  void clear() {
      auto train = this;
      auto prev = train->head;
      auto person = prev->N[0];

      while (person != train->head) {
          auto temp = person;
          person = person->N[person->N[1] != prev];
          if (prev != train->head)
              delete prev;
          prev = temp;
      }
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        unordered_map<string, Train*> M;

        while (n--) {
            string command;
            cin >> command;
            if (command == "NEW") {
                string train1, person;
                cin >> train1 >> person;
                Train* train = new Train(train1, person);
                M[train1] = train;
            }
            else if (command == "BACK") {
                string train2, person;
                cin >> train2 >> person;
                auto train = M[train2];
                train->pushBack(new Wagon(person));
            }
            else if (command == "FRONT") {
                string train2, person;
                cin >> train2 >> person;
                auto train = M[train2];
                train->pushFront(new Wagon(person));
            }
            else if (command == "PRINT") {
                string train2;
                cin >> train2;

                cout << "\"" << train2 << "\":\n";
                auto train = M[train2];
                auto prev = train->head;
                auto person = prev->N[0];

                while (person != train->head) {
                    if (prev != train->head)
                        cout << "<-";
                    cout << person->name;
                    auto temp = person;
                    person = person->N[person->N[1] != prev];
                    prev = temp;
                }
                cout << '\n';
            }
            else if (command == "REVERSE") {
                string train2;
                cin >> train2;
                auto train = M[train2];
                swap(train->head->N[0], train->head->N[1]);
            }
            else if (command == "UNION") {
                string train2, train3;
                cin >> train2 >> train3;
                auto trainFront = M[train2], trainBack = M[train3];
                trainFront->head->N[1]->N[trainFront->head->N[1]->N[1] == trainFront->head] = trainBack->head->N[0];
                trainBack->head->N[0]->N[trainBack->head->N[0]->N[1] == trainBack->head] = trainFront->head->N[1];
                trainBack->head->N[1]->N[trainBack->head->N[1]->N[1] == trainBack->head] = trainFront->head;
                trainFront->head->N[1] = trainBack->head->N[1];
                trainBack->head->N[0] = trainBack->head->N[1] = trainBack->head;
                delete trainBack;
                M.erase(train3);
            }
            else if (command == "DELFRONT") {
                string train1, train2;
                cin >> train1 >> train2;
                auto train = M[train2];
                auto person = train->head->N[0];

                auto newFront = person->N[person->N[1] != train->head];
                newFront->N[newFront->N[1] == person] = train->head;
                train->head->N[0] = newFront;

                string name = person->name;
                delete person;

                Train* trainNew = new Train(train2, name);
                M[train1] = trainNew;

                if (train->head->N[0] == train->head) {
                    M.erase(train->name);
                    delete train;
                }
            }
            else if (command == "DELBACK") {
                string train2, train1;
                cin >> train2 >> train1;
                auto train = M[train2];
                auto person = train->head->N[1];

                auto newBack = person->N[person->N[1] != train->head];
                newBack->N[newBack->N[1] == person] = train->head;
                train->head->N[1] = newBack;

                string name = person->name;
                delete person;

                Train* trainNew = new Train(train2, name);
                M[train1] = trainNew;

                if (train->head->N[0] == train->head) {
                    M.erase(train->name);
                    delete train;
                }
            }
        }

        for (auto [k, v] : M)
            delete v;
    }
}