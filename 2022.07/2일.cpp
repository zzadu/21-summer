#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    for (int i = 0; i < log2(n); i++) {
        a = (a - 1) * 0.5;
        b = (b - 1) * 0.5;
        
        answer++;
        
        if (a++ == b++)
            return answer;
    }

    return answer;
}