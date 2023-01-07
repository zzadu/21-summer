#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int range[2];
    
    sort(routes.begin(), routes.end());

    range[0] = routes[0][0]; range[1] = routes[0][1];
    
    while (!routes.empty()) {
        answer++;
        for (int i = 1; i < routes.size(); i++) {
            if (range[0] <= routes[i][0] && routes[i][0] <= range[1]) {
                range[0] = routes[i][0];
                range[1] = range[1] < routes[i][1] ? range[1] : routes[i][1];
                routes.erase(routes.begin() + i);
                i--;
            }
        }
        routes.erase(routes.begin());
        range[0] = routes[0][0]; range[1] = routes[0][1];
    }
    
    return answer;
}