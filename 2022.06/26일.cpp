#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    
    for (int i = 0; i < s.length();) {
        if (!isalpha(s[i])) {
            ans += s[i];
            i++;
        }
        else if (s[i] == 'z') {
            i += 4;
            ans += '0';
        }
        else if (s[i] == 'o') {
            i += 3;
            ans += "1";
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                i += 3;
                ans += '2';
            }
            else {
                i += 5;
                ans += '3';
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] == 'o') {
                ans += '4';
            }
            else {
                ans += '5';
            }
            i += 4;
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                i += 3;
                ans += '6';
            }
            else {
                i += 5;
                ans += '7';
            }
        }
        else if (s[i] == 'e') {
            i += 5;
            ans += '8';
        }
        else {
            i += 4;
            ans += '9';
        }
    }
    
    return answer = stoi(ans);
}