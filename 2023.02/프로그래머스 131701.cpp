#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int max = *max_element(elements.begin(), elements.end());
    
    vector<int> arr;
    arr.assign(max * elements.size(), 0);
    
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                sum += elements[(j + k) % elements.size()];
            }
            if (arr[sum] == 0) {
            arr[sum] = 1;
            answer++;
            }
        }
    }
    
    
    return answer;
}