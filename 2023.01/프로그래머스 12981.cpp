#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    int fail = 0;
    for (int i = 1; i < words.size(); i++) {
        if (find(words.begin(), words.begin() + i, words[i]) != words.begin() + i) {
            fail = i;
            break;
        }
        else if (words[i - 1][words[i - 1].length() - 1] != words[i][0]) {
            fail = i;
            break;
        }
    }
    
    if (fail) {
        answer[0] = fail % n + 1;
        answer[1] = fail / n + 1;
    }

    return answer;
}