// Hubert Jastrzębski | Informatyka (Szyfr Vigenere'a) | 2021-02-21
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/MjY5OTAxNjA5MzIw/details

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string special = " ,.";
pair<unsigned long, string> cipher(string, string);
string decipher(string, string);

int main()
{
	ifstream in1("dokad.txt");
	ifstream in2("szyfr.txt");
	ofstream out("Vigenere_wyniki.txt");

	out << "ZADANIE 1:\n";
	string text1, key1 = "LUBIMYCZYTAC";
	getline(in1, text1);
	pair<unsigned long, string> result1 = cipher(text1, key1);
	out << "a) " << result1.first << "\nb) " << result1.second << "\n\n";

	out << "ZADANIE 2:\n";
	string text2, key2;
	getline(in2, text2);
	getline(in2, key2);
	string result2 = decipher(text2, key2);
	out << result2 << "\n\n";

	out << "ZADANIE 3:\na) ";
	map<char, unsigned int> amount;
	unsigned int allAmount = 0;
	double k = 0;
	for (char& c : text2) {
		if (special.find(c) == string::npos) {
			amount[c]++;
			allAmount++;
		}
	}
	for (auto& a : amount) {
		out << a.first << ": " << a.second << ", ";
		k += a.second * (a.second - 1.0);
	}
	k = k / (allAmount * (allAmount - 1.0));
	double d = 0.0285 / (k - 0.0385);
	d = round(d * 100) / 100;
	out << "\nb) Dlugosc klucza: " << key2.length() << ", szacowana dlugosc: " << d;

	in1.close();
	in2.close();
	out.close();
}

pair<unsigned long, string> cipher(string text, string key)
{
	pair<unsigned long, string> ciphered = { 0, "" };
	for (int i = 0; i < text.length(); i++) {
		if (special.find(text[i]) != string::npos)
			ciphered.second += text[i];
		else {
			char c = text[i] - alphabet[0];
			char shift = key[(ciphered.first % key.length())] - alphabet[0];
			int result = (c + shift) % alphabet.length();
			ciphered.second += ((char)(result + alphabet[0]));
			ciphered.first++;
		}
	}
	ciphered.first = ceil((float)ciphered.first / key.length());
	return ciphered;
}

string decipher(string text, string key)
{
	string deciphered = "";
	unsigned int keyCounter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (special.find(text[i]) != std::string::npos)
			deciphered += text[i];
		else {
			char c = text[i] - alphabet[0];
			char shift = key[(keyCounter % key.length())] - alphabet[0];
			int result = c - shift;
			if (result < 0)
				result = alphabet.length() + result;
			deciphered += ((char)(result + alphabet[0]));
			keyCounter++;
		}
	}
	return deciphered;
}