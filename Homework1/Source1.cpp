#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter n:"; cin >> n;
	int res = 1;
	//tinh giai thua
	for (int i = 1; i <= n; i++) {
		res = res * i;
	}
	cout << "Result:" << res;
	return 0;
}