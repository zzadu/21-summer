#include <iostream>
#include <queue>
#include <string>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	deque<int> deque;

	string order;
	int n, k;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;
		if (!order.compare("push_back")) {
			cin >> k;
			deque.push_back(k);
		}
		else if (!order.compare("push_front")) {
			cin >> k;
			deque.push_front(k);
		}
		else if (!order.compare("pop_front")) {
			if (deque.empty())
				cout << "-1\n";
			else {
				cout << deque.front() << "\n";
				deque.pop_front();
			}
		}
		else if (!order.compare("pop_back")) {
			if (deque.empty())
				cout << "-1\n";
			else {
				cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		else if (!order.compare("size"))
			cout << deque.size() << "\n";

		else if (!order.compare("empty"))
			cout << deque.empty() << "\n";

		else if (!order.compare("front")) {
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.front() << "\n";
		}
		else if (!order.compare("back")) {
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.back() << "\n";
		}
	}
	return 0;
}
