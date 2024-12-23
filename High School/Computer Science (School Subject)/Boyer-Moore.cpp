// Hubert Jastrzębski | Informatyka (Algorytm Boyera-Moore'a) | 2021-02-01
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/MjMzODc4NjA5NzQ1/details

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string inFile = "tekst.txt";
const string outFile = "wynik.txt";
const string lineSTR = "Linia ";

int main()
{
    ifstream in;
    in.open(inFile);
    string pattern;
    cin >> pattern;
    ofstream out;
    out.open(outFile);

    // wykonywanie dla ka�dej linii tekstu z osobna
    for (int counter = 1; !in.eof(); counter++)
    {
        string text, temp = "";
        getline(in, text);
        int M = pattern.length(), N = text.length();

        // 1) wyznaczenie tablicy shift
        int shift[128];
        for (int i = 0; i < 128; i++)
            shift[i] = M;
        for (int i = M - 1; i >= 0; i--)
            if (shift[pattern[i]] >= M)
                shift[pattern[i]] = M - i - 1;

        // 2) sprawdzenie czy dlugosc wzorca jest dluzsza od tekstu
        if (M > N)
            continue;

        // powtarzenie przeszukiwania a� do sko�czenia si� linii
        int currentPosition = 0;
        while (true) // currentPosition + M <= N
        {
            // 3) i 4) przeszukiwanie tekstu
            int i = currentPosition + M - 1, j = M - 1;
            while (j >= 0)
            {
                // 5) wykonuj dopoki i-ty znak textu rozni sie od j-tego znaku wzorca
                while (text[i] != pattern[j])
                {
                    // 4a) wyznaczanie przesuniecia x
                    int x = shift[text[i]];
                    // 4b) odpowiednie zmienianie wartosci i oraz j
                    if (M - j > x)
                        i += M - j;
                    else
                        i += x;
                    // 4c) stop jesli i jest wieksze od dlugosci tekstu
                    if (i > N)
                        goto endOfLine;
                    // 4d) ustawienie j na ostatni znak wzorca
                    j = M - 1;
                }
                // 6) zmniejszenie i oraz j o jeden
                i--, j--;
            }
            // 7) odnaleziono wzorzec na pozycji i
            temp += to_string(++i) + ", ";
            currentPosition = i + 1;
        }
    endOfLine:
        if (temp != "")
        {
            temp.pop_back();
            temp.pop_back();
            string s = lineSTR + to_string(counter) + ": " + temp + "\n";
            cout << s;
            out << s;
        }
    }

    in.close();
    out.close();
}