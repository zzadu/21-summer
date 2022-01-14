#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> q;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i].at(0) == 'I') {
            q.push_back(stoi(operations[i].substr(2)));
            sort(q.begin(), q.end());
        }
        else if (operations[i].at(2) == '-') {
            if (!q.empty())
                q.pop_front();
        }
        else {
            if (!q.empty())
                q.pop_back();
        }
    }

    if (q.empty())
        answer = { 0, 0 };
    else {
        answer.push_back(q.back()); q.pop_back();
        answer.push_back(q.front()); q.pop_front();
    }

    return answer;
}