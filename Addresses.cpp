#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

class address {

	string city;
	string street;
	int home;
	int apartment;
	
public:
	address(){}
	address(string p_city, string p_street, int p_home, int p_apartment) {
		city = p_city;
		street = p_street;
		home = p_home;
		apartment = p_apartment;
	}
	string collect_line() {
		return city + " " + street + " " + to_string(home) + " " + to_string(apartment);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream in("in.txt");
	ofstream out("out.txt");
	int N;
	in >> N;
	string city, street;
	int home, apartment;

	address* addresses = new address[N];
	

	for (int i = 0; i < N; i++) {
		in >> city >> street >> home >> apartment;
		address a(city, street, home, apartment);
		addresses[i] = a;
	}

	for (int i = 0; i < N; i++) {
		out << addresses[i].collect_line() << endl;
	}
	delete[] addresses;

	in.close();
	out.close();
}