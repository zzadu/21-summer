#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int left = 0, right = 0;
            
            if (j > 0) {
                left = triangle[i - 1][j - 1];
            }
            if (j < triangle[i].size() - 1) {
                right = triangle[i - 1][j];
            }
            
            triangle[i][j] += left > right ? left : right;
        }
    }
    
    int last = triangle.size() - 1;
    
    for (int i = 0; i < triangle[last].size(); i++) {
        if (answer < triangle[last][i])
            answer = triangle[last][i];
    }
    
    return answer;
}