#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i <= yellow; i++) {
        int j = 0;
        if (yellow % i == 0)
            j = yellow / i;
        if ((i + 2) * 2 + (j + 2) * 2 - 4 == brown) {
            answer.push_back(j + 2);
            answer.push_back(i + 2);
            break;
        }
    }
    
    return answer;
}