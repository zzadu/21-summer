#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s < n) {
        answer.push_back(-1);
        return answer;
    }
    
    for (int i = s / n; n != 0;) {
        i = s / n;
        answer.push_back(i);
        n--; s -= i;
        if (n == 1) {
            answer.push_back(s);
            break;
        }
    }
    
    return answer;
}