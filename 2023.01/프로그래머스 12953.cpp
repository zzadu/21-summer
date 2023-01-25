#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer;
    
    sort(arr.begin(), arr.end());
    
    int a = arr[arr.size() - 1], lcm = 0;
    
    while (true) {
        lcm += a;
        int j;
        for (j = 0; j < arr.size() - 1; j++) {
            if (lcm % arr[j] != 0)
                break;
        }
        
        if (j == arr.size() - 1)
            break;
    }
    
    return answer = lcm;
}