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

	bool carry = false, minus = false;
	int sum;

	stack<char> longer = (strlen(a) > strlen(b)) ? stackA : stackB;
	stack<char> shorter = (strlen(a) < strlen(b)) ? stackA : stackB;
	int big = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
	int small = (strlen(a) < strlen(b)) ? strlen(a) : strlen(b);

	if (strlen(a) == strlen(b)) {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] != b[i]) {
				longer = (a[i] > b[i]) ? stackA : stackB;
				shorter = (a[i] < b[i]) ? stackA : stackB;
				if (a[i] < b[i])
					minus = true;
				break;
			}
		}
	}

	for (int i = 0; i < small; i++) {
		sum = 0;
		if (carry)
			sum--;
		sum = sum + (longer.top() - 48) - (shorter.top() - 48);

		if (sum < 0) {
			carry = true;
			sum += 10;
		}
		else
			carry = false;

		result.push((char)(sum + 48));
		longer.pop(); shorter.pop();
	}

	for (int j = 0; j < big - small; j++) {
		sum = 0;
		if (carry) {
			sum = (longer.top() - 48) - 1;
			if (sum < 0) {
				carry = true;
				sum += 10;
			}
			else
				carry = false;

			result.push((char)(sum + 48));
		}
		else
			result.push(longer.top());

		longer.pop();
	}


	if (result.top() == '0') {
		while (result.top() == '0') {
			result.pop();
			if (result.empty()) {
				cout << '0';
				break;
			}
		}
	}

	if (strlen(a) < strlen(b) || minus) {
		cout << '-';
	}

	if (!result.empty()) {
		for (int i = result.size(); i > 0; i--) {
			cout << result.top();
			result.pop();
		}
	}

	return 0;
}