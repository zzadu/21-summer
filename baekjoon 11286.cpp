#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

template <class T> struct absGreater {
	bool operator() (const T& x, const T& y) const {
		if (abs(x) == abs(y)) {
			return x > y;
		}
		return abs(x) > abs(y);
	}
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, absGreater<int>> queue;

	int n;
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (queue.empty()) {
				cout << "0\n";
				continue;
			}
			cout << queue.top() << endl;
			queue.pop();
			continue;
		}
		else {
			queue.push(x);
		}
	}

	return 0;
}