#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    
    // 0일 때
    if (accumulate(works.begin(), works.end(), 0) < n)
        return 0;
    
    // 0 아닐 때
    for (int j = 0; j < works.size(); j++) {
        q.push(works[j]);
    }
    
    while (n != 0) {
        int t = q.top();
        q.pop();
        q.push(t - 1);
        n--;
    }
    
    while (!q.empty()) {
        answer += (long long)pow(q.top(), 2);
        q.pop();
    }
    
    return answer;
}