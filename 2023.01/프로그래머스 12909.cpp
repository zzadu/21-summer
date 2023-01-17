#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    char c;
    int i = 0;
    while (i < s.length()) {
        c = s[i];
        if (c == '(')
            st.push(c);
        else {
            if (st.size() == 0) {
                return false;
            }
            st.pop();
        }
        i++;
    }

    if (st.size() == 0)
        return true;
    else
        return false;
}