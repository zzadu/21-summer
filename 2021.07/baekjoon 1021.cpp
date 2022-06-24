#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main() {

	deque<int> deque;

	int size, m;
	cin >> size;
	cin >> m; // 뽑아내는 수

	for (int k = 0; k < size; k++) {
		deque.push_back(k + 1);
	}

	int index[50];
	for (int i = 0; i < m; i++) {
		cin >> index[i];
	}

	int count = 0;

	for (int j = 0; j < m; j++) {

		int a = 0;
		while (deque[a] != index[j]) {
			a++;
		}

		if (a == 0) {
			deque.pop_front();
			size--;
		}
		else if (a <= size - a) {
			while (deque.front() != index[j]) {
				deque.push_back(deque.front());
				deque.pop_front();
				count += 1;
			}
			deque.pop_front();
			size--;
		}
		else if (size - a < a) {
			while (deque.front() != index[j]) {
				deque.push_front(deque.back());
				deque.pop_back();
				count += 1;
			}
			deque.pop_front();
			size--;
		}
	}

	cout << count;

	return 0;
}