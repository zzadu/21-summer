#include <iostream>
using namespace std;

int fibo(int n, int memo[]) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	memo[n] = (fibo(n - 1, memo) + memo[n - 2]) % 10009;

	return (memo[n - 1] + memo[n - 2]) % 10009;
}

int main() {
	int n, memo[200] = { 0, 1, 1 };
	cin >> n;
	
	cout << fibo(n, memo);

	return 0;
}