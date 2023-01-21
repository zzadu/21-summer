using namespace std;

int solution(int n) {
    int answer = 0;
    
    int f[100000] = {0, 1};
    
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 2] + f[i - 1]) % 1234567;
    }
    
    answer = f[n];
    return answer;
}