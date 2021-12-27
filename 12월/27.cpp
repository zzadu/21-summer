#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, days;
    
    for (int i = 0; i < progresses.size(); i++) {
        if (progresses[i] < 100 && progresses[i] > 0 && speeds[i] <= 100 && speeds[i] > 0) {
        progresses[i] = 100 - progresses[i];
        days.push_back(ceil((double)progresses[i] / speeds[i]));
        }
    }
    
    int distribution = 1, std;
    std = days[0];
    
    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= std)
            distribution++;
        else {
            answer.push_back(distribution);
            distribution = 1;
            std = days[i];
        }
    }
    answer.push_back(distribution);
    
    return answer;
}