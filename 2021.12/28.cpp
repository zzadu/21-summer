#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, max = -1;

   while(true) {
        answer++;

        int j = max + 1, k = max + 1, l = max + 1;

        max = j;
        for (j = j + 1; j < priorities.size(); j++) {
            if (priorities[max] < priorities[j]) {
                max = j;
            }
        }

        if (max == location) {
            break;
        }

        if (location >= l && location < max) {
            location = location + priorities.size() - l;
        }

        for (k; k < max; k++) {
            priorities.push_back(priorities[k]);
        }

    }

    return answer;
}