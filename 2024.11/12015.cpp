#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    int tmp;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<int> temp;
    temp.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (temp[temp.size() - 1] < a[i]) {
            temp.push_back(a[i]);
            continue;
        }
        else if (temp[temp.size() - 1] == a[i]) {
            continue;
        }

        int left = 0, right = temp.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (temp[mid] == a[i]) {
                break;
            }
            else if (temp[mid] > a[i]) {
                right = mid - 1;
            }
            else if (temp[mid] < a[i]) {
                left = mid + 1;
            }
        }
        

        if (temp[mid] < a[i]) {
            temp[mid + 1] = a[i];
        }
        else {
            temp[mid] = a[i];
        }
    }

    cout << temp.size();

    return 0;
}