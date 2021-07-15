#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long t, n, r;

	cin >> t;
	while (t--) {
		cin >> r >> n;

		double result = 1;

		if (r == n)
			result = 1;
		else if (r == 1)
			result = n;
		else {
			if (r > n - r)
				r = n - r;

			int i = 1;

			while (i <= r) {
				result = result * (n--) / (i++);
			}
		}
		cout << (long long)result << "\n";
	}

	return 0;
}