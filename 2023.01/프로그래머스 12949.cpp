#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));
    int a = arr1[0].size(); // arr1[0].size == arr2.size
    
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            for (int k = 0; k < a; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}