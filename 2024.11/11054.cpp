#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // vector<int> asc;
    // asc.push_back(v[0]);

    int maxIndex = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        vector<int> asc;
        asc.push_back(v[0]);

        for (int j = 1; j <= i; j++) {
            if (v[j] == asc[asc.size() - 1]) {
            continue;
            }
            if (v[j] > asc[asc.size() - 1]) {
                asc.push_back(v[j]);
                maxIndex = j;
                continue;
            }

            int left = 0, right = asc.size() - 1;
            int mid;
            while (left <= right) {
                mid = (left + right) / 2;

                if (asc[mid] == v[j]) {
                    break;
                }
                else if (asc[mid] < v[j]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            if (asc[mid] < v[j]) {
                asc[mid + 1] = v[j];
            }
            else {
                asc[mid] = v[j];
            }
        }

        int start = asc.size() - 1;
    

        for (int j = i + 1; j < n; j++) {
            if (v[j] == asc[asc.size() - 1]) {
                continue;
            }
            if (v[j] < asc[asc.size() - 1]) {
                asc.push_back(v[j]);
                continue;
            }

            int left = start, right = asc.size() - 1;
            int mid;
            while (left <= right) {
                mid = (left + right) / 2;

                if (asc[mid] == v[j]) {
                    break;
                }
                else if (asc[mid] < v[j]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            if (asc[mid] > v[j]) {
                asc[mid + 1] = v[j];
            }
            else {
                asc[mid] = v[j];
            }
        }

        int result = asc.size();
        

        if (result > max) {
            max = result;
        }
    }

    
    cout << max;
}