#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int correct = 0, zero = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            zero++;
        }
        else if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            correct++;
        }
    }
    
    answer.push_back((correct + zero) < 2 ? 6 : 7 - correct - zero);
    answer.push_back((correct < 2) ? 6 : 7 - correct);
    
    return answer;
}