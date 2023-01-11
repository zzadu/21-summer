#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int start = 1, gap;
    for (int i = 0; i < stations.size(); i++) {
        gap = stations[i] - start - w;
        answer += ceil((double)gap / (2 * w + 1));
        start = stations[i] + w + 1;
    }
    
    if (start <= n) {
        gap = n - start + 1;
        answer += ceil((double)gap / (2 * w + 1));
    }
    
    return answer;
}