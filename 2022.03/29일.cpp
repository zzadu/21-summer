#include <iostream>
#include <vector>
using namespace std;

int visited[10000] = { 0 };

int counting(int find1, int find2, vector<vector<int>> relation, int m, int index) {

	int cnt = 0;

	if (index != -1) {
		if (relation[index][0] == find2 || relation[index][1] == find2)
			return 0;
	}

	for (int i = 0; i < m; i++) {
		if (relation[i][0] == find1 && !visited[i]) {
			visited[i] = 1;
			cnt += 1 + counting(relation[i][1], find2, relation, m, i);
		}
		if (relation[i][1] == find1 && !visited[i]) {
			visited[i] = 1;
			cnt += 1 + counting(relation[i][0], find2, relation, m, i);
		}
	}

	if (cnt == 0)
		return -1;
	else
		return cnt;
}

int main() {
	int n, m, find1, find2;
	vector<vector<int>> relation;

	cin >> n >> find1 >> find2 >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vector<int> pair = { x, y };
		relation.push_back(pair);
	}

	cout << counting(find1, find2, relation, m, -1);

	return 0;
}