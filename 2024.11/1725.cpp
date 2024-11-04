#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<long long> height;
    height.push_back(1000000001);
    long long t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        height.push_back(t);
    }
    height.push_back(1000000001);

    stack<long long> st1; // 인덱스 저장
    vector<long long> backShorterIndex(n + 1, 0);
    for (int j = n; j >= 0; j--) {
        if (st1.empty()) {
            backShorterIndex[j] = height.size() - 1;
            st1.push(j);
        }
        else if (height[j] <= height[st1.top()]) {
            st1.pop();
            j++;
        }
        else if (height[j] > height[st1.top()]) {
            backShorterIndex[j] = st1.top();
            st1.push(j);
        }
    }

    stack<long long> st2; // 인덱스 저장
    vector<long long> frontShorterIndex(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        if (st2.empty()) {
            frontShorterIndex[j] = 0;
            st2.push(j);
        }
        else if (height[j] <= height[st2.top()]) {
            st2.pop();
            j--;
        }
        else if (height[j] > height[st2.top()]) {
            frontShorterIndex[j] = st2.top();
            st2.push(j);
        }

    }

    long long max = 0;
    for (int k = 1; k <= n; k++) {
        long long extent = (backShorterIndex[k] - frontShorterIndex[k] - 1) * height[k];

        if (max < extent) {
            max = extent;
        }
    }

    cout << max;

    return 0;
}