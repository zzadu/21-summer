#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	char a[100], b[100];
	stack<char> stackA, stackB, result;

	cin >> a >> b;

	for (int i = 0; i < strlen(a); i++)
		stackA.push(a[i]);
	for (int i = 0; i < strlen(b); i++)
		stackB.push(b[i]);

	bool carry = false;
	int big = (strlen(a) >= strlen(b)) ? strlen(a) : strlen(b);
	int small = (strlen(a) < strlen(b)) ? strlen(a) : strlen(b);
	int sum;


	for (int i = 0; i < small; i++) {
		sum = 0;
		if (carry)
			sum++;
		sum = sum + (stackA.top() - 48) + (stackB.top() - 48);

		if (sum >= 10) {
			carry = true;
			sum -= 10;
		}
		else
			carry = false;

		char sumC = sum + 48;
		result.push(sumC);
		stackA.pop(); stackB.pop();
	}

	stack<char> bigger = (stackA.size() >= stackB.size()) ? stackA : stackB;

	for (int j = 0; j < big - small; j++) {
		sum = 0;
		if (carry) {
			sum = sum + (bigger.top() - 48) + 1;
			if (sum >= 10) {
				carry = true;
				sum -= 10;
			}
			else
				carry = false;
			result.push((char)(sum + 48));
		}
		else
			result.push(bigger.top());

		bigger.pop();
	}

	if (carry) {
		result.push((char)'1');
	}

	for (int i = result.size(); i > 0; i--) {
		cout << result.top();
		result.pop();
	}

	return 0;
}