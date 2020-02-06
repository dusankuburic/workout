#include<fstream>
#include<iostream>

using namespace std;

int main() {


	char fileName[80];
	char buffer[255];
	cout << "File name: ";
	cin >> fileName;

	ofstream fout(fileName); //otvara za pisanje
	fout << "This line written directly to the file...\n";
	cout << "Enter text for the file: ";
	cin.ignore(1, '\n');
	cin.getline(buffer, 255); //uzima korisnicki ulaz
	fout << buffer << '\n'; //i zapisuje ga u datoteku
	fout.close(); //zatvara datoteku, spremna je za novo otvoranje


	ifstream fin(fileName);
	cout << "Here's the contents of the file:\n";
	char ch;
	while (fin.get(ch)) {
		cout << ch;
	}

	cout << "\n***End of file contents.***\n";

	fin.close();

	return 0;
}