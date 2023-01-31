#include <string>
#include <stack>
using namespace std;

bool rightString(string s) {
    stack<int> st;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ']' && st.top() == '[') {
            st.pop();
        }
        else if (s[i] == '}' && st.top() == '{') {
            st.pop();
        }
        else if (s[i] == ')' && st.top() == '(') {
            st.pop();
        }
        else
            return false;
    }
    
    return true;
}


int solution(string s) {
    int answer = 0;
    
    if (s.length() % 2 == 1)
        return 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (rightString(s))
            answer++;
        s.push_back(s[0]);
        s.erase(s.begin());
    }
    return answer;
}