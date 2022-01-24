#include <string>
#include <vector>

using namespace std;

void solution2(string begin, string target, vector<string> words, int i, int& change) {

    int diffBW = 0, diffTW = 0;
    for (int j = 0; j < begin.length(); j++) {
        if (begin[j] != words[i][j])
            diffBW++;
        if (target[j] != begin[j])
            diffTW++;
    }

    if (diffTW == 1)
        return;

    if (diffBW == 1) {
        begin = words[i];
        words.erase(words.begin() + i);
        solution2(begin, target, words, 0, ++change);
    }
    else
        solution2(begin, target, words, ++i, change);

    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, change = 0;
    bool targetE = false;

    for (int k = 0; k < words.size(); k++) {
        if (words[k] == target)
            targetE = true;
    }

    if (!targetE)
        return 0;

    solution2(begin, target, words, 0, change);


    return answer = change + 1;
}