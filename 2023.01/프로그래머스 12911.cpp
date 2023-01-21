using namespace std;

int binary(int n) {
    int cnt = 0;
    
    while (true) {
        if (n == 1)
            break;
        if (n % 2 == 1)
            cnt++;
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = n + 1;
    
    int nCnt = binary(n);
    
    while (true) {
        if (binary(answer) == nCnt) {
            break;
        }
        else
            answer++;
    }
    
    return answer;
}