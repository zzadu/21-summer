#include <iostream>
using namespace std;

void print(int n, int& sum) {
	if (n == 0)
		return;
	
	sum += n;

	print(n - 1, sum);
}

int main() {
	int n, sum = 0;
	cin >> n;
	
	print(n, sum);
	cout << sum;

	return 0;
}