#include <string>
#include <vector>
using namespace std;

int binary(string s, int& c) {
    if (s == "1")
        return 0;
    
    c++;
    
    int zeroCnt = 0, oneCnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            oneCnt++;
        else {
            zeroCnt++;
        }
    }
    
    s = "";
    
    while (true) {
        if (oneCnt < 1)
            break;
        if (oneCnt % 2 == 1)
            s += '1';
        else
            s += '0';
        oneCnt /= 2;
    }
    
    return zeroCnt + binary(s, c);
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    int cnt = 0;
    answer[1] = binary(s, cnt);
    answer[0] = cnt;
    
    return answer;
}