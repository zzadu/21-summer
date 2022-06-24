#include <iostream>
using namespace std;

void star(int n) {
	if (n == 0)
		return;
	star(n - 1);
	cout << "*";
}

void triangle(int n) {
	if (n == 0)
		return;
	triangle(n - 1);
	star(n);
	cout << "\n";
}

int main() {

	int n;
	cin >> n;

	triangle(n);

	return 0;
}