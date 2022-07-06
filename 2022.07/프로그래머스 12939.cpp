#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string solution(string s) {
    string answer = "";
    int mn = 999999999, mx = -999999999;
    
    char ss[10000000];
    strcpy(ss, s.c_str());
    
    char* sub = strtok(ss, " ");
    while (sub != NULL) {

        mx = max(mx, (int)stoi(sub));
        mn = min(mn, (int)stoi(sub));

        sub = strtok(NULL, " ");
    }
                 
    return answer = to_string(mn) + ' ' + to_string(mx);
}