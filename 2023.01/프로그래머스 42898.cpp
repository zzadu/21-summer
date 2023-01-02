#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int paths[100][100] = {0};
    paths[0][0] = 1;
    
    for (int k = 0; k < puddles.size(); k++) {
            paths[puddles[k][1] - 1][puddles[k][0] - 1] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paths[i][j] != -1) {
                if (i != 0 && paths[i - 1][j] != -1) {
                    paths[i][j] += paths[i - 1][j]; // 위
                }
                if (j != 0 && paths[i][j - 1] != -1) {
                    paths[i][j] += paths[i][j - 1]; // 왼쪽
                }
                
                paths[i][j] %= 1000000007;
            }
        }
    }
    
    answer = paths[n - 1][m - 1];
    return answer;
}