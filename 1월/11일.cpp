#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0, i;
    int clothes[30] = { 0 };
    
    for (i = 0; i < lost.size(); i++) {
        clothes[lost[i] - 1]--;
    }
    for (i = 0; i < reserve.size(); i++) {
        clothes[reserve[i] - 1]++;
    }
    
    for (i = 0; i < n; i++) {
        if (clothes[i] == -1) {
            if (i > 0 && clothes[i - 1] > 0) {
                clothes[i]++;
                clothes[i - 1]--;
            }
            else if (i < n - 1 && clothes[i + 1] > 0) {
                clothes[i]++;
                clothes[i + 1]--;
            }
        }
    }
    
    int num = 0;
    for (i = 0; i < n; i++) {
        if (clothes[i] >= 0)
            num++;
    }
    
    return answer = num;
}