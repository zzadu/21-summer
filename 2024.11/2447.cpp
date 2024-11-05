#include <iostream>
using namespace std;

void printStar(int x, int y) {
    if (x == 0 && y == 0) {
        cout << "*";
        return;
    }

    if (x % 3 == 1 && y % 3 == 1) {
        cout << ' ';
        return;
    }
    else {
        printStar(x / 3, y / 3);
    }

    return;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printStar(i, j);
        }
        cout << "\n";
    }

    return 0;
}