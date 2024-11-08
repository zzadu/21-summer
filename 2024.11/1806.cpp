#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {

    int n, s;
    cin >> n >> s;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int idx1 = 0, idx2 = 0;
    int min = n;
    int sum = v[idx1];
    while (idx1 < n && idx2 < n) {
        if (sum >= s) {
            if (idx2 - idx1 + 1 < min) {
                min = idx2 - idx1 + 1;
            }
            sum -= v[idx1];
            idx1++;
        }
        else if (sum < s) {
            idx2++;
            sum += v[idx2];
        }
    }

    if (accumulate(v.begin(), v.end(), 0) < s) {
        min = 0;
    }

    cout << min;


    return 0;
}