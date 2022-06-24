#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for (int i = 0; i < scoville.size(); i++)
        q.push(scoville[i]);

    while (q.size() != 1 && q.top() < K) {
        int x, y;
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        q.push(x + (y * 2));
        answer++;

        if (q.top() >= K)
            break;
    }

    if (q.top() < K)
        answer = -1;

    return answer;
}