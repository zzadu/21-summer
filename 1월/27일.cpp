/* bfs로 풀고 마지막 예제가 안 돼서 dfs도 같이 해야 되는 건가 했는데 그냥 동서남북
    어디로 먼저 가는지 순서가 중요한 거였음... 한참 붙들고 있었는뎅 -.-
    큐에 넣어주는 순서 바꿔주니까 바로 되자낭. . . ?
    */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

string s[100];
int visit[100][100] = { 0 };
int cnt[100][100] = { 0 };
queue<pair<int, int>> q;

void bfs(pair<int, int> a, int n, int m) {

	int x = a.first, y = a.second;
	if (x == n - 1 && y == m - 1)
		return;

	if (x < n - 1 && s[x + 1][y] == '1' && !visit[x + 1][y]) { // 남
		q.push({ x + 1, y });
		visit[x + 1][y] = 1;
		cnt[x + 1][y] = cnt[x][y] + 1;
	}
	if (x > 0 && s[x - 1][y] == '1' && !visit[x - 1][y]) { // 북
		q.push({ x - 1, y });
		visit[x - 1][y] = 1;
		cnt[x - 1][y] = cnt[x][y] + 1;
	}
	if (y < m - 1 && s[x][y + 1] == '1' && !visit[x][y + 1]) { // 동
		q.push({ x, y + 1 });
		visit[x][y + 1] = 1;
		cnt[x][y + 1] = cnt[x][y] + 1;
	}
	if (y > 0 && s[x][y - 1] == '1' && !visit[x][y - 1]) { // 서
		q.push({ x, y - 1 });
		visit[x][y - 1] = 1;
		cnt[x][y - 1] = cnt[x][y] + 1;
	}

	q.pop();
	bfs(q.front(), n, m);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
		

	q.push({ 0, 0 });
	visit[0][0] = 1;
	cnt[0][0] = 1;
	bfs(q.front(), n, m);

	cout << cnt[n - 1][m - 1];


	return 0;
}