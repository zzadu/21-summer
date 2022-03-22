#include <iostream>
#include <vector>
using namespace std;

void findVirus(vector<vector<int>> virus, int infection[], int n, int connected, int start) {

	for (int i = 0; i < connected * 2; i++) {
		if (virus[i][0] == start && !infection[virus[i][1] - 1]) {
			infection[virus[i][1] - 1] = 1;
			findVirus(virus, infection, n, connected, virus[i][1]);
		}
	}

}

int main() {

	int n, connected, x, y, sum = 0;
	vector<vector<int>> virus;
	int infection[100] = { 1 };

	cin >> n >> connected;

	for (int i = 0; i < connected; i++) {
		cin >> x >> y;
		vector<int> pair1, pair2;
		pair1.push_back(x); pair1.push_back(y);
		pair2.push_back(y); pair2.push_back(x);
		virus.push_back(pair1); virus.push_back(pair2);
	}


	findVirus(virus, infection, n, connected, 1);

	for (int i = 1; i < n; i++) {
		if (infection[i] == 1)
			sum++;
	}

	cout << sum;

	return 0;
}