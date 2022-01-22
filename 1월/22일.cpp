#include <string>
#include <vector>

using namespace std;

void solution1(int n, vector<vector<int>> computers, int i, int visit[]) {
    visit[i] = 1;
    int connect = 0;
    
    for (int k = 0; k < n; k++) {
        if (i != k && computers[i][k] == 1 && visit[k] == 0) {
            solution1(n, computers, k, visit);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visit[200] = { 0 };
    
    solution1(n, computers, 0, visit);
    
    for (int i = 0; i < n; i++)
        if (!visit[i]) {
            solution1(n, computers, i, visit);
            answer++;
        }
    

    return answer + 1;
}