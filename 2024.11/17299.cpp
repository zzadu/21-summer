#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    int n;
    cin >> n;

    int tmp;
    vector<int> cnt(1000001, 0);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
        cnt[tmp]++;
    }

    stack<int> st;
    st.push(-1);
    vector<int> result(n, 0);
    for (int j = n - 1; j >= 0; j--) {
        if (st.top() == -1) {
            result[j] = -1;
            st.push(v[j]);
            continue;
        }

        if (cnt[st.top()] > cnt[v[j]]) {
            result[j] = st.top();
            st.push(v[j]);
        }
        else {
            st.pop();
            j++;
        }
    }

    for (int k = 0; k < n; k++) {
        cout << result[k] << " ";
    }

    return 0;
} 