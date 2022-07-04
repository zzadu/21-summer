#include <string>
#include <vector>
#include <stack>
using namespace std;

bool correct(string p) {
    stack<char> pp;
    
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            pp.push(p[i]);
        else {
            if (!pp.empty())
                pp.pop();
            else
                return false;
        }
    }
    
    return true;
}

string solution(string p) {
    string answer = "";
    
    if (p == "")
        return answer;
    if (correct(p))
        return p;
    
    int left = 0, right = 0, i;
    for (i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            left++;
        else
            right++;
        
        if (left == right)
            break;
    }
    
    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);
    
    if (correct(u))
        answer = u + solution(v);
    else {
        answer += "(" + solution(v) + ")";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(')
                answer += ")";
            else
                answer += "(";
        }
    }
    
    
    return answer;
}