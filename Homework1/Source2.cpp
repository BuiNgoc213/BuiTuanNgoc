#include<iostream>

using namespace std;

int main() {
	int numb;
	do {
		cout << "Enter a Positive Integer:"; cin >> numb;
	} while (numb <= 0);
	return 0;
}