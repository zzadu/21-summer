#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int i = 0;
    char c;
    while (s[i]) {
        c = s[i];
        if (i != 0 && s[i - 1] == ' ')
            s[i] = toupper(c);
        else
            s[i] = tolower(c);
        i++;
    }
    
    if (!isdigit(s[0]))
        s[0] = toupper(s[0]);
    
    return answer = s;
}