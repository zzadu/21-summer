#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long start = 0, end = (long long)times[times.size() - 1] * (long long)n, mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        long long sum = 0;
        
        for (int i = 0; i < times.size(); i++) {
                sum += mid / (long long)times[i];
        }
        
        if (sum >= n) {
            answer = mid;
            end = mid - 1;
        }
        else if (sum < n) {
            start = mid + 1;
        }
    }
    
    return answer;
}