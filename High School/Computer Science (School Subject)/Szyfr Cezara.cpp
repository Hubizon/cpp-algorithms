// Hubert Jastrzębski | Informatyka (Szyfr Cezara) | 2021-02-12
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/MjcwMDMzNTEyNDEw/details

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
const string textFile = "text.txt";
const string codedFile = "szyfrogram.txt";
const string decryptedFile = "odszyfrowany.txt";
const string chooseSTR = "Wybierz:\nszyfrownanie - s\nodszyfrowywanie - o\nkoniec - q\n";
const string loopSTR = "Wybierz ponownie. (koniec - q)\n";
const string endSTR = "\nDziekuje za wspolprace!\n";

// SZYFR CEZARA UMO�LIWIAJ�CY KODOWANIE I DEKODOWANIE WIELU LINII ORAZ S��W ODZIELONYCH SPACJAMI
int main()
{
    char x;
    cout << chooseSTR;
    cin >> x;
    while (x != 'q')
    {
        if (x == 's')
        {
            ifstream in(textFile);
            ofstream out(codedFile);
            cout << "Wprowad� klucz:\n";
            int key;
            cin >> key;
            key %= alphabet.length();
            string text;
            while (!in.eof())
            {
                getline(in, text);
                for (char& c : text) {
                    if (c == ' ')
                        c = alphabet[alphabet.length() - (alphabet.length() - key + 1) * (key != 0)];
                    else
                        c = alphabet[(c - 'A' + key) % alphabet.length()];
                }
                out << text << '\n';
            }
            in.close();
            out.close();
        }
        else
        {
            ifstream in(codedFile);
            ofstream out(decryptedFile);
            cout << "Wprowad� klucz:\n";
            int key;
            cin >> key;
            key %= alphabet.length();
            string text;
            while (!in.eof())
            {
                getline(in, text);
                for (char& c : text) {
                    if (c == ' ')
                        c = alphabet[alphabet.length() - key - 1];
                    else if (c == alphabet.length() - key - 1)
                        c = ' ';
                    else
                        c = alphabet[((c - 'A' - key) + (c - key < 'A') * alphabet.length()) % alphabet.length()];
                }
                out << text << '\n';
            }
            in.close();
            out.close();
        }
        cout << loopSTR;
        cin >> x;
    }
    cout << endSTR;
}