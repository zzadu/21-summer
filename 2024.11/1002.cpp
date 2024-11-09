#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int distance1to2 = pow((x1 - x2), 2) + pow((y1 - y2), 2);

        if (distance1to2 == 0) {
            if (r1 == r2) {
                cout << "-1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (distance1to2 == (int)pow(r1 + r2, 2) || distance1to2 == (int)pow(abs(r1 - r2), 2)) {
            cout << "1\n";
        }
        else if (distance1to2 > (int)pow(abs(r1 - r2), 2) && distance1to2 < (int)pow(r1 + r2, 2)) {
            cout << "2\n";

        }
        else {
            cout << "0\n";
        }

    }   
}