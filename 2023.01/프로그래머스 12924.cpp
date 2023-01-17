using namespace std;

int solution(int n) {
    int answer = 1; // 연속된 숫자 한 개
    
    if (n == 1)
        return 1;
    
    if (n % 2 == 1) // 연속된 숫자 두 개
        answer++;
    
    for (int i = 3; i < n; i++) {
        if (n % i == 0 && i % 2 == 1) { // 홀수 개의 연속된 숫자
            if (n / i - i / 2 >= 1 || n / i + i / 2 <= n) {
                if (n / i % 2 == 1) { // 가운데 숫자 홀수이면
                    if (n % 2 == 1) // 합이 반드시 홀수
                        answer++;
                }
                else {              // 가운데 숫자 짝수이면
                    if (n % 2 == 0) // 합이 반드시 짝수
                        answer++;
                }
            }
        }
    }
    
    return answer;
}