#include <algorithm>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long weight = (long long)w, height = (long long)h;
    
    if (w == 1 || h == 1) {
        return 0;
    }
    else if (w == h) {
        return weight * height - weight;
    }
    else if (w % h == 0 || h % w == 0) {
        return weight * height - max(weight, height);
    }
    long long gcd;
    
    for (long long i = min(weight, height); i > 0; i--) {
        if (weight % i == 0 && height % i == 0) {
            gcd = i;
            break;
        }
    }
    
    answer = (weight * height - (weight + height - gcd));
    
    return answer;
}