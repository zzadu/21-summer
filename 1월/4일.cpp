#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int l = 0; l < commands.size(); l++) {
        vector<int> sorting;

        if (commands[l][0] == commands[l][1])
            answer.push_back(array[commands[l][0] - 1]);
        else {
            for (int i = commands[l][0]; i <= commands[l][1]; i++) {
                sorting.push_back(array[i - 1]);
            }

            sort(sorting.begin(), sorting.end());

            answer.push_back(sorting[(commands[l][2] - 1)]);
        }
    }

    return answer;
}