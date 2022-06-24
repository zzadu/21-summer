#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	stack<char> st, copy;
	char num[200];
	cin >> num;

	for (int i = 0; i < n; i++) {
		st.push(num[i]);
	}

	for (int i = 1; i <= n; i++) {
		copy.push(st.top());
		st.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << copy.top();
		copy.pop();
		if ((n - i - 1) % 3 == 0 && (i != n -1))
			cout << ',';
	}

	return 0;
}