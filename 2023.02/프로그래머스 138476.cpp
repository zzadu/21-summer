#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    int size = *max_element(tangerine.begin(), tangerine.end());
    
    vector<int> v;
    v.assign(size, 0);
    
    for (int i = 0; i < tangerine.size(); i++) {
        v[tangerine[i] - 1]++;
    }
    
    sort(v.rbegin(), v.rend());
    int j = 0;
    
    while (k > 0) {
        k -= v[j++];
        answer++;
    }
    
    return answer;
}