#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int visitedDFS[1001] = { 0 };
int visitedBFS[1001] = { 0 };
vector<vector<int>> s;

void dfs(int n, int m, int start) {
	int go;

	if (visitedDFS[start])
		return;

	visitedDFS[start] = 1;
	cout << start + 1 << " ";

	for (int j = 0; j < m; j++) {
		if (s[j][0] == start) {
			go = s[j][1];
			if (!visitedDFS[go])
				dfs(n, m, go);
		}
		else if (s[j][1] == start) {
			go = s[j][0];
			if (!visitedDFS[go])
				dfs(n, m, go);
		}
	}

	return;
}

void bfs(queue<int>& q, int m) {
	if (q.empty())
		return;

	visitedBFS[q.front()] = 1;
	cout << q.front() + 1 << " ";

	for (int i = 0; i < m; i++) {
		if (s[i][0] == q.front() && !visitedBFS[s[i][1]]) {
			visitedBFS[s[i][1]] = 1;
			q.push(s[i][1]);
		}
		else if (s[i][1] == q.front() && !visitedBFS[s[i][0]]) {
			visitedBFS[s[i][0]] = 1;
			q.push(s[i][0]);
		}
	}

	q.pop();
	bfs(q, m);
}

int main() {

	queue<int> q;

	int n, m, v;
	cin >> n >> m >> v;

	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		int small = v1 < v2 ? v1 : v2;
		int big = v1 > v2 ? v1 : v2;
		s.push_back({ small - 1, big - 1 });
	}

	sort(s.begin(), s.end());

	dfs(n, m, v - 1);
	q.push(v - 1);
	cout << "\n";
	bfs(q, m);

	return 0;
}