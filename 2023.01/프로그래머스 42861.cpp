#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[2] == b[2])
        if (a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int visited[100] = {0};
    
    sort(costs.begin(), costs.end(), compare);
    
    visited[costs[0][0]] = 1;
    int uni = 2;
    
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0], end = costs[i][1];
        cout << start << " " << end << endl;
        if (!visited[start] && !visited[end]) { // 둘 다 방문 X
            answer += costs[i][2];
            visited[start] = uni; visited[end] = uni++;
        }
        else if (visited[end] == 0 && visited[start]) { // end 방문 X
            answer += costs[i][2];
            visited[end] = visited[start];
        }
        else if (visited[start] == 0 && visited[end]) {
            answer += costs[i][2];
            visited[start] = visited[end];
        }
        else if (visited[start] != visited[end]) {
            answer += costs[i][2];
            int bigU = visited[start] > visited[end] ? visited[start] : visited[end];
            int smallU = visited[start] < visited[end] ? visited[start] : visited[end];
            for (int i = 0; i < n; i++) {
                if (visited[i] == bigU)
                    visited[i] = smallU;
            }
        }
    }
    
    return answer;
}