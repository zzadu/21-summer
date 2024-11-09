#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    long n, k;
    cin >> n >> k;

    long left = 1, right = k;
    long mid;
    long sum;

    while (left <= right) {
        mid = (left + right) / 2;
        sum = 0;
        for (long j = 1; j <= n; j++) {
            sum += (mid / j) > n ? n : (mid / j) ;
        }

        if (sum < k) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << left;


    return 0;
}