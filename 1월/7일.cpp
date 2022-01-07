#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = { 1, 2, 3, 4, 5 };
    vector<int> second = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int firstCnt = 0, secondCnt = 0, thirdCnt = 0, i;
    
    for (i = 0; i < answers.size(); i++) {
        if (answers[i] == first[i % first.size()])
            firstCnt++;
        if (answers[i] == second[i % second.size()])
            secondCnt++;
        if (answers[i] == third[i % third.size()])
            thirdCnt++;
    }
    
    int max;
    int correct[3];
    
    correct[0] = firstCnt; correct[1] = secondCnt; correct[2] = thirdCnt;
    max = *max_element(correct, correct + 3);
    
    for (i = 0; i < 3; i++) {
        if (correct[i] == max)
            answer.push_back(i + 1);
    }

    return answer;
}