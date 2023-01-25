#include <vector>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long a[2001] = {0, 1, 2, 0};
    
    for (int i = 3; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 1234567;
    }
    
    return answer = a[n];
}