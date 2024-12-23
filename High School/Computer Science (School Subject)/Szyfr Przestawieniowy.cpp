// Hubert Jastrzębski | Satori A01 (Szyfr przestawieniowy) | 2021-02-22
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/Mjc3MTkwMTE1NDk4/details

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string cipher(vector<string>&, vector<int>);
string cipher2(string&, vector<int>);

int main()
{
	// TEST:
	vector<string> text = { "INFORMATYKA" };
	vector<int> key = {3, 2, 5, 4 , 1};
	cout << cipher(text, key);

	// ZADANIE 1:
	ifstream in1("szyfr1.txt");
	ofstream out1("wyniki_szyfr1.txt");
	vector<string> text1(6);
	vector<int> key1(50);
	for (int i = 0; i < 6; i++)
		getline(in1, text1[i]);
	for (int i = 0; i < 50; i++)
		in1 >> key1[i];
	out1 << cipher(text1, key1);

	// ZADANIE 2:
	ifstream in2("szyfr2.txt");
	ofstream out2("wyniki_szyfr2.txt");
	string text2;
	vector<int> key2(15);
	getline(in2, text2);
	for (int i = 0; i < 15; i++)
		in2 >> key2[i];
	out2 << cipher2(text2, key2);

	// ZADANIE 3:
	ifstream in3("szyfr3.txt");
	ofstream out3("wyniki_szyfr3.txt");
	string text3;
	getline(in3, text3);
	vector<int> key3 = { 6, 2, 4, 1, 5, 3 };
	out3 << cipher2(text3, key3);
}

string cipher(vector<string>& text, const vector<int> key)
{
	string result;
	for (int i = 0; i < text.size(); i++) {
		string& tempText = text[i];
		for (int j = 0; j < tempText.size(); j++) {
			char& c1 = tempText[j];
			char position = key[j % key.size()] - 1;
			char& c2 = tempText[position];
			swap(c1, c2);
		}
		result += tempText + '\n';
	}
	return result;
}

string cipher2(string& text, const vector<int> key)
{
	for (int i = 0; i < text.size(); i++) {
		char& c1 = text[i];
		char position = key[i % key.size()] - 1;
		char& c2 = text[position];
		swap(c1, c2);
	}
	return text;
}